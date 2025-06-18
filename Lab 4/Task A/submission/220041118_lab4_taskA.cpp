#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;



void pre()
{
    fastio;
}

void dijkstra(vector<vector<pair<ll, ll>>>& adjList, vector<ll>& dist) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (wt > dist[u]) continue;
        for (auto [v, w] : adjList[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve(int tc)
{
    ll n, m;
    cin >> n >> m;

    ll u, v, w;
    vector<vector<pair<ll, ll>>> adjList(n + 1);
    while (m --> 0) {
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    dijkstra(adjList, dist);

    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
    cout << endl;

}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}