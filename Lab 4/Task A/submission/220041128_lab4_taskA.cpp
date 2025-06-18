#include<iostream>
#include<bits/stdc++.h>


using namespace std;

typedef long long int ll;

const ll MAX= 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;;
    cin>>n>>m;

    vector<vector<pair<int, int>>> graph(n + 1);


    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        
    }

    vector<ll> dist(n + 1, MAX);
    dist[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

   
    for (int i = 1; i <= n; ++i)
    {
        cout << dist[i] << " ";
    }
    cout <<endl;

    return 0;
}