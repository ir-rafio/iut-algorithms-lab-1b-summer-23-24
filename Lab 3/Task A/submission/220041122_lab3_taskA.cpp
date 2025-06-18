#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

vector<vector<int>> adj; //adjacency list
vector<int> money;
vector<bool> visited; //visited vector to keep track of nodes status

void pre()
{
    fastio;


}

void dfs(int u, vector<int>& members) {
    visited[u] = true;
    members.push_back(u);
    for (int v : adj[u]) {//neighbours check
        if (!visited[v]) {
            dfs(v, members);
        }
    }
}

bool solve(int tc)
{
    int n, m;
        cin >> n >> m;

        adj.assign(n, {});
        money.resize(n);
        visited.assign(n, false);//by default not visited

        for (int i = 0; i < n; ++i) {
            cin >> money[i];
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool possible = true;
        int totalMoney = accumulate(money.begin(), money.end(), 0);

        if (totalMoney % n != 0) {
            possible = false;
        }
        else {
            int target = totalMoney / n;
            for (int i = 0; i < n && possible; ++i) {
                if (!visited[i]) {
                    vector<int> group;
                    dfs(i, group); //depth first search through relations - to find connected ppl

                    long long groupSum = 0;
                    for (int person : group) {
                        groupSum += money[person];//total money
                    }

                    if (groupSum / group.size() != target) { //if target not possible
                        possible = false;
                    }
                }
            }
        }
        return possible;

}

signed main()
{
    pre();

    int tc, T = 1;
    cin >> T;

    for(tc = 1; tc <= T; tc++)
    {
        cout << "Case " << tc << ": "<< (solve(tc) ? "Yes" : "No");
        cout << '\n';
    }

    return 0;
}





