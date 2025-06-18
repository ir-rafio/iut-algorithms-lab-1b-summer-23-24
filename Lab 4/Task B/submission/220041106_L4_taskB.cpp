#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef long long ll;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        vector<int> speed(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> speed[i];
        }

        vector<ll> dist(n + 1, 1000000000000000); 
        dist[1] = 0;
    }
}