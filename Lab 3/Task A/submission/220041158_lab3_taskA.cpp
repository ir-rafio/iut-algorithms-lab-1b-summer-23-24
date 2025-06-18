#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;





void bfs(int start, vector<vector<int>> &graph,  vector<bool> &visited, vector<int> &money, long long &total, int &count) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        total += money[node];
        count++;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

signed main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<int> money(n);
        for (int i = 0; i < n; ++i) {
            cin >> money[i];
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v; 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        bool possible = true;

        for (int i = 0; i < n && possible; ++i) {
            if (!visited[i]) {
                long long total = 0;
                int count = 0;
                bfs(i, graph, visited, money, total, count);
                if (total % count != 0) {
                    possible = false;
                }
            }
        }

        cout << "Case " << t << ": ";
        if(possible){
           cout << " Yes"<< endl;
        }else 
        cout<< " No"<< endl;
    }

    return 0;
}
