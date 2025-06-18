#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void DFS(lli v, vector<vector<lli>>& graph, vector<bool>& visited,
         vector<vector<lli>>& cc, vector<lli>& current_cc) {
    visited[v] = true;
    current_cc.push_back(v);
    for (auto i = graph[v].begin(); i != graph[v].end(); ++i) {
        if (!visited[*i])
            DFS(*i, graph, visited, cc, current_cc);
    }
}
void soln() {
    lli n, e, sum = 0;
    cin >> n >> e;
    vector<lli> money(n);
    for (lli i = 0; i < n; i++) {
        cin >> money[i];
        sum += money[i];
    }
    vector<vector<lli>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<vector<lli>> cc;
    vector<lli> current_cc;
    lli nodes, neighbor;
    for (lli i = 0; i < e; i++) {
        cin >> nodes >> neighbor;
        graph[nodes].push_back(neighbor);
        graph[neighbor].push_back(nodes);
    }
    lli ct = 0;
    set<lli> eqs;
    for (lli i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        current_cc.clear();
        DFS(i, graph, visited, cc, current_cc);
        cc.push_back(current_cc);
        ct++;
    }
    // cout << ct << enl;
    if (ct == 1) {
        if (sum % n == 0)
            cout << "Yes" << enl;
        else
            cout << "No" << enl;
        return;
    } else {
        for (lli i = 0; i < (lli)cc.size(); i++) {
            lli sz = cc[i].size();
            lli eq = 0;
            for (lli j = 0; j < sz; j++) {
                lli ix = cc[i][j] - 1;
                eq += money[ix];
            }
            if (eq % sz == 0) {
                eqs.insert(eq / sz);
            } else {
                cout << "No" << enl;
                return;
            }
        }
    }
    if (eqs.size() == 1)
        cout << "Yes" << enl;
    else
        cout << "No" << enl;
}
int main() {
    fast();
    lli t = 1;
    lli ti = 1;
    cin >> t;
    while (t--) {
        cout << "Case " << ti++ << ": ";
        soln();
    }
}
// Author: tashobi_02 //
