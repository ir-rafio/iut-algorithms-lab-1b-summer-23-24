#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void DFS(LL v, vector<vector<LL>>& graph, vector<bool>& visited,
         vector<vector<LL>>& cc, vector<LL>& current_cc) {
    visited[v] = true;
    current_cc.push_back(v);
    for (auto i = graph[v].begin(); i != graph[v].end(); ++i) {
        if (!visited[*i])
            DFS(*i, graph, visited, cc, current_cc);
    }
}
void soln() {
    LL n, e, sum = 0;
    cin >> n >> e;
    vector<LL> money(n);
    for (LL i = 0; i < n; i++) {
        cin >> money[i];
        sum += money[i];
    }
    vector<vector<LL>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<vector<LL>> cc;
    vector<LL> current_cc;
    LL nodes, neighbor;
    for (LL i = 0; i < e; i++) {
        cin >> nodes >> neighbor;
        graph[nodes].push_back(neighbor);
        graph[neighbor].push_back(nodes);
    }
    LL ct = 0;
    set<LL> eqs;
    for (LL i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        current_cc.clear();
        DFS(i, graph, visited, cc, current_cc);
        cc.push_back(current_cc);
        ct++;
    }
    
    if (ct == 1) {
        if (sum % n == 0)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    } else {
        for (LL i = 0; i < (LL)cc.size(); i++) {
            LL sz = cc[i].size();
            LL eq = 0;
            for (LL j = 0; j < sz; j++) {
                eq += cc[i][j];
            }
            if (eq % sz == 0) {
                eqs.insert(eq / sz);
            } else {
                cout << "No" << "\n";
                return;
            }
        }
    }
    if (eqs.size() == 1)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
}
int main() {
    fast();
    LL t = 1;
    LL ti = 1;
    cin >> t;
    while (t--) {
        cout << "Case " << ti++ << ": ";
        soln();
    }
}

