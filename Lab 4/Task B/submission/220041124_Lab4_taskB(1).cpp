#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const LL INF = 1e18;

int t, n, m;
vector<pair<int, int>> adj[1005]; // adjacency list: (neighbor, weight)
int speed[1005]; // speed of bike in each city
LL dist[1005][1005]; // dist[city][bike_speed]

void pre() {
    fastio;
}

void dijkstra() {
    priority_queue<tuple<LL, int, int>, vector<tuple<LL, int, int>>, greater<>> pq;

    // Start at city 1 with its own bike
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 1000; ++j)
            dist[i][j] = INF;

    dist[1][speed[1]] = 0;
    pq.emplace(0, 1, speed[1]);

    while (!pq.empty()) {
        auto [time, u, spd] = pq.top(); pq.pop();
        if (time > dist[u][spd]) continue;

        // Try switching to local bike at current city
        int new_spd = speed[u];
        if (dist[u][new_spd] > time) {
            dist[u][new_spd] = time;
            pq.emplace(time, u, new_spd);
        }

        // Try moving to neighbor
        for (auto &[v, w] : adj[u]) {
            LL new_time = time + 1LL * w * spd;
            if (dist[v][spd] > new_time) {
                dist[v][spd] = new_time;
                pq.emplace(new_time, v, spd);
            }
        }
    }
}

void solve(int tc) {
    cin >> n >> m;

    // Clear previous test case data
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // undirected
    }

    // Read bike speeds
    for (int i = 1; i <= n; ++i) {
        cin >> speed[i];
    }

    dijkstra();

    // Output minimum time to reach city n
    LL ans = INF;
    for (int spd = 1; spd <= 1000; ++spd) {
        ans = min(ans, dist[n][spd]);
    }

    cout << ans << '\n';
}

signed main() {
    pre();

    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve(tc);
    }

    return 0;
}

