#include <bits/stdc++.h>
using namespace std;

vector<int> shortestSignals(int n, vector<pair<int, int>> adj[], int S)
{

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int delay = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (delay > dist[node])
            continue;

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[adjNode])
            {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> result = shortestSignals(n, adj, 1);

    for (int i = 1; i <= n; ++i)
    {
        if (result[i] == INT_MAX)
            cout << -1 << " ";
        else
            cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}