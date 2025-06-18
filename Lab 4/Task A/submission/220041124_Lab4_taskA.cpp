#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const LL inf = 1e15;

vector<pair<LL, LL>> adj[100005]; 
vector<LL> dist(100005, inf);

void dijkstra(int start, int n) {
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, cost] : adj[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
}

void pre() {
    fastio;
}

void solve(int tc) {
    LL n,m;
    cin>>n>>m;

    for (LL i = 0;i<m;++i) {
        LL a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
    }

    dijkstra(1,n);

    for (int i=1;i<=n;++i) {
        cout << dist[i] << " ";
    }
    cout<<'\n';
}

signed main() {
    pre();

    int tc = 1;
    // Only one test case needed for this problem
    solve(tc);

    return 0;
}

