#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
typedef pair<ll, ll> pr;
const int MAX = 1e5 + 5;
const ll INF = 1e18;

vector<pr> adj[MAX];
ll dist[MAX];

void pre() {
    fastio;
}

void addEdge(int u, int v, ll w) {
    adj[u].push_back({w, v});
}

void dijkstra(int src, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[src] = 0;

    priority_queue<pr, vector<pr>, greater<pr>> Q;
    Q.push({0, src});

    while (!Q.empty()) {
        auto [currDist, u] = Q.top();
        Q.pop();

        if (currDist > dist[u]) continue;

        for (auto [weight, v] : adj[u]) { //relaxation
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                Q.push({dist[v], v});
            }
        }
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    dijkstra(1, n);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << '\n';
}

signed main() {
    pre();

    int tc = 1;

    for (int t = 1; t <= tc; t++) {
        solve(t);
    }

    return 0;
}
