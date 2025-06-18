#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

int dist[100];
vector<vector<pair<int,int>>> graph(1000);


void dijkstra(int n, int s)
{
    for(int i=0; i<n; i++)
        dist[i] = 999999;
    dist[s] = 0;

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>>pq;

    pq.push({0,s});

    while(!pq.empty())
    {
        pair<int,int> u = pq.top();
        pq.pop();


        for(auto e : graph[u.first])
        {
            if(dist[e.first] > dist[u.first] + e.second)
            {
                dist[e.first] = dist[u.first] + e.second;
               // cout << dist[u.first] + e.second;
                pq.push({dist[e.first] , e.first});
            }
        }

    }
}

void solve(int tc)
{
    int n,m,a,b,c;

    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    dijkstra(n,1);

    for(int i=0; i<n; i++)
        cout << dist[i] << " ";

    return 0;
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
