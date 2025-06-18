#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}


int bfs(int node, int visited[],vector<vector<int>> graph)
{
    queue<int> Q;
    int temp,comp = 0;
    Q.push(node);
    visited[node] = 1;
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        int siz = graph[temp].size();
        for(int i=0; i<siz; i++)
        {
            int nextnode = graph[temp][i];
            if(!visited[nextnode])
            {
                visited[nextnode] = 1;
                Q.push(nextnode);
                comp++;
            }
        }
    }
    return comp;
}


void solve(int tc)
{
    int n,p,id1,id2,country = 0,sum = 0;
    cin >> n >> p;
    int visited[n] = {0};
    vector<int> comps;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<p; i++)
    {
        cin >> id1 >> id2;
        graph[id1].push_back(id2);
        graph[id2].push_back(id1);
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            int c = bfs(visited[i],visited,graph);
            comps.push_back(c+1);
            //cout << c+1 << " " << endl;
            country++;
        }
    }
    //cout << country << endl;
    for(int i=0; i<country; i++)
    {
        for(int j=i+1; j<country; j++)
        {
            //cout << comps[i] << comps[j] << endl;
            sum += comps[i]*comps[j];
        }
    }
    cout << sum << endl;
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
