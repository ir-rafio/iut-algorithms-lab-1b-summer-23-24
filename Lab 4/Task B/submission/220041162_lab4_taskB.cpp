#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

struct Edge { int to; int len; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin>> n>>m;

        vector<vector<Edge>> adj(n+1);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> s(n+1);
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }

        vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));

        // min-heap time, u, k
        using State = tuple<ll,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[1][1] = 0;
        pq.emplace(0LL, 1, 1);

        while(!pq.empty()){
            auto [d,u,k] = pq.top();
            pq.pop();
            if(d > dist[u][k]) continue;
            ll curSpeed = s[k];

            // buy part at u
            if(s[u] < curSpeed && d < dist[u][u]){
                dist[u][u] = d;
                pq.emplace(d, u, u);
            }

            // travel to road
            for(auto &e : adj[u]){
                int v = e.to;
                ll nd = d + curSpeed * e.len;
                if(nd < dist[v][k]){
                    dist[v][k] = nd;
                    pq.emplace(nd, v, k);
                }
            }
        }

        ll ans = INF;
        for(int k = 1; k <= n; k++){
            ans = min(ans, dist[n][k]);
       }
    cout << ans<<"\n";
    return 0;
      }

    return 0;
}


