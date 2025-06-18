#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void relation(int start, vector<vector<int>> &peo, vector<bool> &visited, vector<int> &money, long long &sum, int &count) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    sum = money[start];
    count = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : peo[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                sum += money[v];
                count++;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; ++caseNo) {
        int n, m;
        cin >> n >> m;

        vector<int> money(n);
        for (int i = 0; i < n; ++i) {
            cin >> money[i];
        }

        vector<vector<int>> peo(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--; 
            peo[u].push_back(v);
            peo[v].push_back(u);
        }

        vector<bool> visited(n, false);
        bool normal = true;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                long long sum = 0;
                int count = 0;
                relation(i, peo, visited, money, sum, count);
                if (sum % count != 0) {
                    normal = false;
                    break;
                }
            }
        }

        cout << "Case " << caseNo << ": " << (normal? "Yes" : "No") << "\n";
    }

    return 0;
}
