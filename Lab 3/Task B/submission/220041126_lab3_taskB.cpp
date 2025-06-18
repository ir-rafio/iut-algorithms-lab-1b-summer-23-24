#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
using LL = long long;

int counter = 0;
void dfs(int i, vector<bool> &visited, vector<vector<int>> &adj)
{
    counter++;
    visited[i] = true;
    for (auto &&i : adj[i])
    {
        if (!visited[i])
         dfs(i, visited, adj);
    }
}

void pre()
{
    fastio;
}

void solve(int tc)
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> v(n);
    int a, b;
    vector<bool> visited(n, false);
    while (m--)
    {
        cin >> a >> b;
        v[b].push_back(a);
        v[a].push_back(b);
    }
    long long  temp;
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,v);
        }
        if(i == 0)
        {
            result += counter*(n-counter);
             temp = counter;
        }
        else
        {
            result += (counter-temp)*(n-counter+temp);
            temp =counter;
        }
    }
    
    cout << result/2 << '\n';
}

signed main()
{
    pre();

    int tc, tt = 1;

    for (tc = 1; tc <= tt; tc++)
    {
        solve(tc);
        cout << '\n';
    }

    return 0;
}

