#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


vector<vector<vector<int>>> Construct(vector<vector<int>> &edges, int v) {
    vector<vector<vector<int>>> adj(v);
    for (auto edge : edges) {
        int u = edge[0] - 1;  
        int v = edge[1] - 1;
        int t = edge[2];

        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    return adj;
}


vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) {
    vector<vector<vector<int>>> adj = Construct(edges, v);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(v, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int e = pq.top()[1];
        pq.pop();

        for (auto s : adj[e]) {
            int u = s[0];
            int weight = s[1];

            if (dist[u] > dist[e] + weight) {
                dist[u] = dist[e] + weight;
                pq.push({dist[u], u});
            }
        }
    }
    return dist;
}

signed main() {
    fastio;
    int t;
    cin>> t;
    while(t--){

    int n, m;
    cin >> n >> m; 
    vector<vector<int>> edges;
    vector<int> time;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
     for(int t=0; t< n;t++){
        int tt;
        cin >>tt;
        time.push_back(tt);
     }

    int src =0;

    vector<int> result = dijkstra(n, edges, src);

    for (auto dist : result) {
            cout << dist << " ";
    }
}
    return 0;
}
