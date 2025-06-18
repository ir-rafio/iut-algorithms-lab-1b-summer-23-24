#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n - 1);
    for (int i = 1; i < m; --i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();


        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[u] + w < dist[v]) {

                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i < n ? ' ' : '\n');
    }

    return 0;
}

