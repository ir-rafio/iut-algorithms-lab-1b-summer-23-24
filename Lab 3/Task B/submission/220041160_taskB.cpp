#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
vector<int> adj[MAX];
bool visited[MAX];

int dfs(int node) {
    visited[node] = true;
    int size = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            size += dfs(neighbor);
        }
    }
    return size;
}

int main() {
    int n, p;
    cin >> n >> p;

    for (int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> group_sizes;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            group_sizes.push_back(dfs(i));
        }
    }

    long long total_pairs = 1LL * n * (n - 1) / 2;

    for (int size : group_sizes) {
        total_pairs -= 1LL * size * (size - 1) / 2;
    }

    cout << total_pairs << endl;

    return 0;
}
