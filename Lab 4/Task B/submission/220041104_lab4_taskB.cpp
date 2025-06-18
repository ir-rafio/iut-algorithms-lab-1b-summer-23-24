#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define inf 1000000000000000000

struct node {
    int vertex;
    int distance;

    node(int vertex, int distance) : vertex(vertex), distance(distance) {}
    node() {}

    bool operator < (const node &other) const {
        return this->distance > other.distance;
    }
};

vector<int> adj[1005];
vector<int> cost[1005];
vector<int> dist(1005, inf);

void dijkstra(int source, int s[], int n){
    priority_queue<node> pq;
    pq.push({source, 0});
    dist[source] = 0;

    int time = inf;

    while( !pq.empty() ){
        node x = pq.top();
        pq.pop();
        time = min(time, s[x.vertex]);

        if(dist[x.vertex] < x.distance)
            continue;

        for(int i=0; i<adj[x.vertex].size(); i++){
            int vertex = adj[x.vertex][i];
            int distance = cost[x.vertex][i] * time;

            if(dist[vertex] > dist[x.vertex] + distance){
                dist[vertex] = dist[x.vertex] + distance;
                pq.push({vertex, dist[vertex]});
            }
        }
    }
}

void compress(int s[], int n){
    int x = inf;

    for(int i=1; i<=n; i++){
        x = min(x, s[i]);

        for(int j=0; j<adj[i].size(); j++){
            int new_cost = cost[i][j] * x;
            cost[i][j] = new_cost;
        }
    }
}

void rewind(int n){
    for(int i=0; i<=n; i++){
        adj[i].clear();
        cost[i].clear();
        dist[i] = inf;
    }
}

void pre()
{
    fastio;
}

void solve(int tc)
{
    int n, m;
    cin>>n>>m;
    int s[n+1];

    rewind(n+3);

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    for(int i=1; i<=n; i++)
        cin>>s[i];

    //compress(s, n);
    dijkstra(1, s, n);

    cout<<dist[n]<<"\n";
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
