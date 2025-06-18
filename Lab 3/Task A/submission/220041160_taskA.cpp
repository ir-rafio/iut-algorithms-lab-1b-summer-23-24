

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> edges[MAXN];
int funds[MAXN];
bool seen[MAXN];

int members, total_funds;

void dfs(int curr) {
    seen[curr] = true;
    ++members;
    total_funds += funds[curr];
    for (int neighbor : edges[curr]) {
        if (!seen[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    for (int tc = 1; tc <= test_cases; ++tc) {
        int n, m;
        cin >> n >> m;

        int global_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> funds[i];
            global_sum += funds[i];
            edges[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        cout << "Case " << tc << ": ";
        if (global_sum % n != 0) {
            cout << "No\n";
            continue;
        }

        int avg_fund = global_sum / n;
        memset(seen, false, sizeof(seen));
        bool valid = true;

        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                members = 0;
                total_funds = 0;
                dfs(i);
                if (total_funds != members * avg_fund) {
                    valid = false;
                    break;
                }
            }
        }

        cout << (valid ? "Yes" : "No") << '\n';
    }

    return 0;
}


