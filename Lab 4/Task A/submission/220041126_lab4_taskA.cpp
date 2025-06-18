#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const LL inf = 1e15;

vector<pair<LL, LL>> adj_list[100005]; 
vector<LL> D(100005, inf);

void dijkstra(int start_indx) {
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<>> pq;
    D[start_indx] = 0;
    pq.push({0, start_indx});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > D[u]) continue;

        for (auto &[v, cost] : adj_list[u]) {
            if (D[v] > D[u] + cost) {
                D[v] = D[u] + cost;
                pq.push({D[v], v});
            }
        }
    }
}

void pre() {
    fastio;
}

void solve(int tc) {
    LL n,m;
    cin>>n>>m;

    for (LL i = 0;i<m;++i) {
        LL a,b,c;
        cin>>a>>b>>c;
        adj_list[a].emplace_back(b,c);
    }

    dijkstra(1);

    for (int i=1;i<=n;++i) {
        cout << D[i] << " ";
    }
    cout<<'\n';
}

signed main() {
    pre();

    int tc = 1;
    solve(tc);

    return 0;
}