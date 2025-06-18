#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &count)
{
    vis[node] = 1;
    count++;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, count);
        }
    }
}

vector<int> dfsOFgraph(vector<vector<int>> &adj, int &v)
{
    vector<int> vis(v, 0);
    vector<int> same_country;
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            count = 0;
            dfs(i, adj, vis, count);
            same_country.push_back(count);
        }
    }
    return same_country;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> same_country = dfsOFgraph(adj, n);
    int size = same_country.size(), x = 0, ans = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            x = same_country[i] * same_country[j];
            ans = ans + x;
        }
    }
    cout << ans << endl;
    return 0;
}