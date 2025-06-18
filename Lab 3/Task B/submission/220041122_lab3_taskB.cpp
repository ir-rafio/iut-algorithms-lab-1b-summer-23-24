#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u, vector<int>& group) {
    visited[u] = true;
    group.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, group);
        }
    }
}

int main() {
    fastio;

    int n, p;
    cin >> n >> p;

    adj.assign(n, {});
    visited.assign(n, false);

    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> c_sizes;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> countries;
            dfs(i, countries); //finding countries
            c_sizes.push_back(countries.size());
        }
    }

    LL total = (LL)n * (n - 1) / 2; //total possible pairs
    for (int N : c_sizes) {
        total -= (LL)N * (N - 1) / 2; //same country pairs subtracted
    }

    cout << total << '\n';

    return 0;
}

