#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;



void pre()
{
    fastio;
}

class node {
public:
    ll city;
    ll speed;
};


void dijkstra(vector<vector<pair<ll, ll>>>& adjList, vector<ll>& dist, vector<ll>& s) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 1});
    ll minS = s[1];

    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();
        if (wt > dist[u]) continue;
        for (auto [v, w] : adjList[u]) {
            // cout  << u << ' ' << v << ' ' << w << endl;
            if (dist[v] > dist[u] + w * minS) {
                dist[v] = dist[u] + w * minS;
                pq.push({dist[v], v});
            }
            if (minS > s[v]) {
                minS = s[v];
                dist[u] += dist[v] + minS * w; 
            }
            // cout << v << ' ' << minS << endl;
        }
    }
}

void solve(int tc)
{
    ll n, m;
    cin >> n >> m;

    ll u, v, w;
    vector<vector<pair<ll, ll>>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> s[i];



    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    dijkstra(adjList, dist, s);

    // for (int i = 1; i <= n; i++) cout << dist[i] << ' ';

    cout << dist[n];

}

signed main()
{
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