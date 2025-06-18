#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAX =  10005;
vector<vector<int>> adj(MAX);
bool visited[MAX];
int money[MAX];

int comp_sum;
int comp_count;

void dfs(int node)
{
    visited[node] = true;
    comp_sum += money[node];
    comp_count++;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int tc= 1; tc <= T; tc++)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> money[i];
            total += money[i];
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1); 
            adj[v - 1].push_back(u - 1);
        }

        if (total % n != 0)
        {
            cout << "Case " << tc << ": No\n";
            continue;
        }

        int target = total / n;
        bool possible = true;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                comp_sum = 0;
                comp_count = 0;
                dfs(i);

                if (comp_sum % comp_count != 0 || comp_sum / comp_count != target)
                {
                    possible = false;
                    break;
                }
            }
        }

       if(possible)
            cout << "Case " << tc << ": Yes\n";
        else
            cout << "Case " << tc << ": No\n";
    }

    return 0;
}
