#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const LL INF = 1e18;

void pre()
{
    fastio;
    
}

void solve(int tc)
{
    int n, m;
    
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n+1);

    for(int i = 0; i < m; ++i) {
        int a, b, c;

        cin >> a >> b >> c;

        adjList[a].emplace_back(b, c);
    }


    // Dijsktra

    vector<LL> dist(n+1, INF);

    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<> > pq;

    dist[1] = 0;

    pq.push({0, 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adjList[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        // solve(tc);
        solve(1);
        cout << '\n';
    }

    return 0;
}