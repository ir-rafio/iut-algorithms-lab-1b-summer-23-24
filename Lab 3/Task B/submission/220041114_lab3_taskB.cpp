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
    int size;
    vector<bool>visited;
    graph(int vert){
        V=vert;
        adjlist.resize(V);
        
        visited.resize(V,false);
    }
    void addedge(int u,int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int bfs(int s){
        int size=1;
        queue<int>q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neighbour:adjlist[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);
                    size++;
                }  
            }
        }
        return size;
    }
};
void solve(int tc)
{
    int n,p;
    cin>>n>>p;
    graph g(n);
    
    while(p--){
        int u,v;
        cin>>u>>v;
        
        g.addedge(u,v);
    }
    vector<int>countrysize;
    for(int i=0;i<n;i++){
        if(!g.visited[i]){
            int size=g.bfs(i);
            countrysize.push_back(size);
        }
    }
    LL totalpair=(LL)n*(n-1)/2;
    LL samecount=0;
    for(int size:countrysize){
        samecount+=(LL)size*(size-1)/2;
    }
    cout<<totalpair-samecount;
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;
    
    // for(tc = 1; tc <= tt; tc++)
    // {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    // }

    return 0;
}