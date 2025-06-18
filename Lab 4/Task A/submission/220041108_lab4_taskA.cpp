#include <bits/stdc++.h>
#define int long long
#define inf 2000000000000000000
#define mod 998244353
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
using LL = long long;

void pre()
{
    fastio;
}
vector<int> adj[200005];
vector<int> cost[200005];
vector<int> dist(200005, inf);
struct node
{
    int vertex;
    int distance;
    node() {}
    node(int vertex, int distance) : vertex(vertex), distance(distance) {}
    bool operator<(const node &other) const
    {
        return this->distance > other.distance;
    }
};

void dijkstra(int source = 1)
{
    priority_queue<node> pq;
    pq.push({source, 0});
    dist[source] = 0;

    while (!pq.empty())
    {
        node x = pq.top();
        pq.pop();

        if (x.distance > dist[x.vertex])
            continue;

        for (int i = 0; i < adj[x.vertex].size(); i++)
        {
            int vertex = adj[x.vertex][i];
            int distance = cost[x.vertex][i];

            if (dist[vertex] > x.distance + distance)
            {
                dist[vertex] = x.distance + distance;
                pq.push({vertex, dist[vertex]});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int u, v, x;
        cin >> u >> v >> x;

        adj[u].push_back(v);

        cost[u].push_back(x);
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";

    cout << "\n";
}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;

    for (tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}

