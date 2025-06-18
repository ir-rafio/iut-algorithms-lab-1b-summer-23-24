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
    lli n, e;
    cin >> n >> e;
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
    for (lli i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        current_cc.clear();
        DFS(i, graph, visited, cc, current_cc);
        cc.push_back(current_cc);
        ct++;
    }
    lli ans = 0;
    lli cps = n * (n - 1) / 2;
    for (lli i = 0; i < (lli)cc.size(); i++) {
        lli sz = (lli)cc[i].size();
        ans += (sz * (sz - 1)) / 2;
    }
    cout << cps - ans << enl;
}
int main() {
    fast();
    lli t = 1;
    //  cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
