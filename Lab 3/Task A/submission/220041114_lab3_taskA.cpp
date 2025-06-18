#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}
struct graph{
    vector<vector<int>> adjlist;
    int V;
    vector<int>money;
    vector<bool>visited;
    graph(int vert){
        V=vert;
        adjlist.resize(V);
        money.resize(V);
        visited.resize(V,false);
    }
    void addedge(int u,int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    void bfs(int s,vector<int>& component){
        queue<int>q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            component.push_back(node);
            for(int neighbour:adjlist[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);

                }  
            }
        }
    }
};
void solve(int tc)
{
    int n,m;
    cin>>n>>m;
    graph g(n);
    for(int i=0;i<n;i++){
        cin>>g.money[i];
    }
    while(m--){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g.addedge(u,v);
    }
    bool possible=true;
    for(int i=0;i<n;i++){
        if(!g.visited[i]){
            vector<int>component;
            g.bfs(i,component);
            LL total=0;
            for(int p:component){
                total+=g.money[p];
            }
            if(total%component.size()!=0){
                possible=false;
                
            }
        }
    }
    if(possible) cout<<"Yes";
    else cout<<"No";
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}