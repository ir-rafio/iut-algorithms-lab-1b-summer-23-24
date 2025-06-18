#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void bfs(int node, int visited[], vector<vector<int>> graph)
{
    queue<int> Q;
    int temp;
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
            }
        }
    }
}

int main()
{
    int t,n,m,u,v,sum = 0;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        cin >> n >> m;
        int ar[n],visited[n];
        vector<vector<int>> graph(n+1);
        for(int j=0; j<n; j++)
        {
            cin >> ar[j];
            sum += ar[j];
        }
        for(int j=0; j<m; j++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(sum%n != 0)
        {
            cout << "Case " << i << ":" << "No" << endl;
            break;
        }
        bfs(node,visited,graph);

    }
    return 0;
}
