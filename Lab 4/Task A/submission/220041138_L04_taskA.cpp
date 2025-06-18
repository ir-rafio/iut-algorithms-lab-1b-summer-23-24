#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    ll a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); // city,cost
    }
    vector<ll> dist(n + 1, 1e18);
    dist[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // cost,city
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll cost = pq.top().first;
        ll distCity = pq.top().second;
        pq.pop();
        if (dist[distCity] < cost)
            continue;
        for (auto it : adj[distCity])
        {
            if (dist[it.first] > cost + it.second)
            {
                dist[it.first] = cost + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}