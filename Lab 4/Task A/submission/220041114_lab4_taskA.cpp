#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}
struct graph{
    vector<vector<pair<int,int>>>adjlist;
    int V;
    vector<long long>distance;
    
    
    graph(int vert){
        V=vert;
        adjlist.resize(V);
        
        distance.resize(V,1e18);
        
    }
    void addedge(int u,int v,int w){
        adjlist[u].emplace_back(v,w);
    }
    void dijkstra(int src){
        distance[src]=0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0,src);
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            
            if(d>distance[u]) continue;
            for(auto[v,weight]:adjlist[u]){
                if(distance[u]+weight<distance[v]){
                    distance[v]=distance[u]+weight;
                    pq.emplace(distance[v],v);
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
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        g.addedge(a,b,c);
        
    }
    g.dijkstra(0);
    for(int i=0;i<g.distance.size();i++){
        cout<<g.distance[i]<<" ";
    }
    cout<<endl;
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}