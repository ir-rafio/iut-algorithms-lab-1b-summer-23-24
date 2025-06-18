#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int T, n, m;
vector<int> adj[MAX];
int money[MAX];
bool visited[MAX];

void bfs(int start, long long& totalMoney, int& cnt) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    totalMoney = money[start];
    cnt = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                totalMoney += money[v];
                cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> n >> m;

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            visited[i] = false;
            cin >> money[i];
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool possible = true;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                long long totalMoney = 0;
                int cnt = 0;
                bfs(i, totalMoney, cnt);
                if (totalMoney % cnt != 0) {
                    possible = false;
                    break;
                }
            }
        }

        cout << "Case " << tc << ": " << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}
