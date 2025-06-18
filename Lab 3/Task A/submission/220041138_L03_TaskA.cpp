#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
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
    }
    return 0;
}