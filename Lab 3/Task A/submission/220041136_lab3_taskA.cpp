#include <iostream>
#include <vector>
using namespace std;

vector<int> money;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int person, int& totalMoney, int& count) {
    visited[person] = true;
    totalMoney += money[person];
    count++;

    for (int neighbor : adj[person]) {
        if (!visited[neighbor]) {   
            dfs(neighbor, totalMoney, count);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int n, m;
        int totalMoney = 0, count = 0;
        cin >> n >> m;

        money.resize(n);
        adj.assign(n, {});
        visited.assign(n, false);

        for (int i = 0; i < n; ++i) {
            cin >> money[i];
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;  // Convert to 0-based index
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool canDistribute = true;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                
                dfs(i, totalMoney, count);

                if (totalMoney % count != 0) {
                    canDistribute = false;
                    break;
                }
            }
        }

        cout << "Case " << test << ": " << (canDistribute ? "Yes" : "No") << endl;
    }

    return 0;
}
