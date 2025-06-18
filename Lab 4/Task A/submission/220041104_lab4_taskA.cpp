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

vector<int> adj[100005];
vector<int> cost[100005];
vector<int> dist(100005, inf);

void dijkstra(int source){
    priority_queue<node> pq;
    pq.push({source, 0});
    dist[source] = 0;

    while( !pq.empty() ){
        node x = pq.top();
        pq.pop();

        if(dist[x.vertex] < x.distance)
            continue;

        for(int i=0; i<adj[x.vertex].size(); i++){
            int vertex = adj[x.vertex][i];
            int distance = cost[x.vertex][i];

            if(dist[vertex] > dist[x.vertex] + distance){
                dist[vertex] = dist[x.vertex] + distance;
                pq.push({vertex, dist[vertex]});
            }
        }
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

    while(m--){
        int u, v, d;
        cin>>u>>v>>d;

        adj[u].push_back(v);
        cost[u].push_back(d);
    }

    dijkstra(1);

    for(int i=1; i<=n; i++)
        cout<<dist[i]<<" ";

    cout<<"\n";
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
