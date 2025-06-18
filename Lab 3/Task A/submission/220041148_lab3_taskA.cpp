#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
vector<int> graph[MAX];
int money[MAX];
bool visited[MAX];

int people_count, money_sum;

void dfs(int node) {
    visited[node] = true;
    people_count++;
    money_sum += money[node];
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++) {
        int n, m;
        cin >> n >> m;

        
        int total_money = 0;
        for (int i = 0; i < n; i++) {
            cin >> money[i];
            total_money += money[i];
            graph[i].clear();
        }

        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;           
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << "Case " << case_num << ": ";

        
        if (total_money % n != 0) {
            cout << "No" << endl;
            continue;
        }

        int target = total_money / n;
        memset(visited, false, sizeof(visited));

        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                people_count = 0;
                money_sum = 0;
                dfs(i);
                if (money_sum != people_count * target) {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}
