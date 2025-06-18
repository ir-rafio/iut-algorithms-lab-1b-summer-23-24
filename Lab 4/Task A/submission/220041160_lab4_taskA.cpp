#include<bits/stdc++.h>
#include<vector>
#include<queue>



using namespace std;
#define int long long


const int INF = 1e18;




signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n,m;

    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);


    for(int i=0; i<m ;i++){
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].emplace_back(b,c);
    }

    vector<int> dist(n+1,INF);
    dist[1]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;


    pq.push({0,1});

    while(!pq.empty()){
        auto[cost,u] = pq.top();
        pq.pop();

        if(cost>dist[u]) continue;

        for(auto [v,v_cost] : adj[u]){
            if(dist[u] + v_cost < dist[v]){
                dist[v]=dist[u]+v_cost;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i=1 ;i<=n ;i++){
        cout<< dist[i]<<" ";
    }

}

