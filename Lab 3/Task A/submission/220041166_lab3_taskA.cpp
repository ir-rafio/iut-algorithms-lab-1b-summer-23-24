#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void pre() {
    fastio;
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<int> money(n);
    for (int i = 0; i < n; ++i)
        cin >> money[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    bool possible = true;

    function<void(int, int&, int&)> dfs = [&](int u, int& totalMoney, int& count) {
        visited[u] = true;
        totalMoney += money[u];
        count++;

        for (int v : adj[u]) {
            if (!visited[v])
                dfs(v, totalMoney, count);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int totalMoney = 0, count = 0;
            dfs(i, totalMoney, count);
            if (totalMoney % count != 0) {
                possible = false;
                break;
            }
        }
    }

    cout << "Case " << tc << ": " << (possible ? "Yes" : "No") << endl;
}

signed main() {
    pre();

    int tt;
    cin >> tt;

    for (int tc = 1; tc <= tt; ++tc) {
        solve(tc);
    }

    return 0;
}

