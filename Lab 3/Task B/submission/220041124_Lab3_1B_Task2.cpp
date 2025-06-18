#include<bits/stdc++.h>
using namespace std;

#define LL long long

const LL MAXN=1e5+5;
vector<LL>adj[MAXN];
vector<bool>vis(MAXN);
LL cs;

void dfs(int u) {
    vis[u] = true;
    cs++;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main(){
    LL n,m;cin>>n>>m;
    LL u,v;
    for(LL i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<LL>gs;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cs=0;
            dfs(i);
            gs.push_back(cs);
        }
    }

    LL ans=(n*(n-1))/2;
    //cout<<ans<<"\n";
    LL sp=0;
    for(auto &i:gs){
        //cout<<i<<"\n";
        sp+=((i*(i-1))/2);
    }
    ans-=sp;
    cout<<ans<<"\n";

    
}