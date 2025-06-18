#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
using LL = long long;
const int N = 1e5 + 10; 



void pre() {
    fastio;
}

void solve(int tc) {
    int v, e, v1, v2, w;
    cin >> v >> e;
    vector<pair<int,int>> g[v+1];
    for(int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> w;
        g[v1].push_back({v2, w});
    }

    vector<int> dist(v+1, N);
    dist[1] = 0;

    priority_queue<
        pair<int,int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
    > pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;
        if(d > dist[u]) continue;

        for(auto &e : g[u]) {
            int v = e.first;
            int w = e.second;
            int cand = d + w;
            if(cand < dist[v]) {
                dist[v] = cand; 
                pq.push({cand, v}); 
            }
        }
    }

    for(int i = 1; i <= v; i++) {
        cout << dist[i] << (i == v ? '\n' : ' ');
    }
    return;
}

signed main() {
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}