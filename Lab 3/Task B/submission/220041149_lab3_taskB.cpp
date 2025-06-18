#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}
int nways(vector<vector<int>>& adjl, int vert)
{
    vector<bool>visited(vert, false);
    
    vector<LL> component;
    
    
    int ans =0;
    for(int i=0; i<vert; ++i)
    {
        if(!visited[i])
        {
            queue<int> q;
            

            visited[i] = true;
            q.push(i);
            LL count = 1;

            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                
                int sz = adjl[temp].size();
                for(int k=0; k<sz; ++k)
                {
                    int next = adjl[temp][k];
                    if(!visited[next])
                    {
                       visited[next] = true;
                       q.push(next);
                       count ++;

                    }
                }
            }
            component.push_back(count);
            
        }
    }
    LL total = 0, prefix = 0;
    for (LL group : component) {
        total += group * prefix; 
        prefix += group;
    }

    return total;
    
}

void solve()
{
    int vert , edges;
    cin>>vert>> edges;
   
    vector<vector<int>> adjl;
    adjl.resize(vert);
    

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        u; v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    LL ans = nways(adjl, vert);
    cout<<ans<<"\n";
}

signed main()
{
    pre();

    solve();

    return 0;
}


/*


*/