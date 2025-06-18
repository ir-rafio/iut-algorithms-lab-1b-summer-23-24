#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, count);
        }
    }
}


signed main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> adj(n);
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> Size;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, adj, visited, count);
            Size.push_back(count);
        }
    }

    long long total = 0;
    long long sum = 0;

    for (int size : Size) {
        total += sum * size;
        sum += size;
    }

    cout << total << endl;
    return 0;
}
