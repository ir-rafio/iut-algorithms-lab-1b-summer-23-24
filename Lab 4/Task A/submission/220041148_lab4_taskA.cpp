#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {

    int n, m;
    cin >> n >> m;

    
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, cost] : graph[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }

    return 0;
}
