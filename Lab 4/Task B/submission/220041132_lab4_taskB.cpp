#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const LL INF = 1e18;

void pre()
{
    fastio;

    
}

void solve(int tc)
{
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n+1);
    vector<int> time(n+1); // time per unit distance

    for(int i = 0; i < m; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    for(int i = 1; i <= n; ++i) {
        cin >> time[i];
    }

    // Dijsktra

    vector<LL> sTime(n+1, INF);

    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<> > pq;

    sTime[1] = 0;

    pq.push({0, 1});

    int minTime = time[1];

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if(minTime > time[u]) {
            minTime = time[u];
        }

        if (d > sTime[u]) continue;

        for (auto [v, w] : adjList[u]) {
            if (sTime[u] + w * minTime < sTime[v]) {
                sTime[v] = sTime[u] + w * minTime;
                pq.push({sTime[v], v});

                if(minTime > time[v]) {
                    minTime = time[v];
                    sTime[u] = sTime[v] + minTime * w;
                }
            }
        }
    }

    cout << sTime[n] << '\n';
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