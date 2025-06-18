#include<bits/stdc++.h>
using namespace std;

long long inf = 1E14;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i=0; i<m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back(b, c);
    }
    vector<long long> d(n+1, inf);
    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<long long, int>, greater<>> pq;

    pq.push(0, 1);

    while(!pq.empty())
    {
        auto [s, u] = pq.top();
        pq.pop();
    }
    return 0;
}
