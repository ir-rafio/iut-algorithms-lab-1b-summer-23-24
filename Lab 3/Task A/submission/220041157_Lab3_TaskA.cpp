#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int> &adj, vector<int> &money, vector<bool> &visited, int &totalMoney, int &totalPeople)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    totalMoney = 0;
    totalPeople = 0;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        totalMoney += money[current];
        totalPeople++;

        for(int neighbour : adj[current])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push[neighbour];
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for(int c=0; c<T; c++)
    {
        int n, m;
        cin >> n >> m;

        vector<int> money(n);

        for(int i=0; i<n; i++)
            cin >> money[i];
        vector<vector<int>> adj(n);

        for(int i=0; i<m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(u);
            adj[v].push_back(v);
        }
        vector<bool> visited(n, false);
        bool possible = true;

        for(int i=0; i< (n && possible); i++)
        {
            if(!visited[i])
            {
                int totalMoney = 0;
                int totalPeople = 0;

                bfs(i, adj, money, visited, totalMoney, totalPeople);

                if(totalMoney % totalPeople != 0)
                    possible = false;
            }
        }
        cout << "Case " << c << ": " << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}
