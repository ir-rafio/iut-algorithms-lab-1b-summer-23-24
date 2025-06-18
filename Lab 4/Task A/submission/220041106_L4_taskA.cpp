#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll,int>pli;

int main(){
    int n,m;
    cin >> n >> m;
    
    vector<vector<pli>> adj(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
    }

    vector<ll> dist(n+1, 1000000000000000000);
    dist[1] = 0;

    priority_queue<pli,vector<pli>, greater<pli>> pq;
    pq.push(make_pair(0,1));

    while(!pq.empty()){
        pli top = pq.top();
        pq.pop();
        ll d = top.first;
        int u = top.second;

        if(d > dist[u]){
            continue;
        }
        for(int i=0; i<adj[u].size();i++){
            int v = adj[u][i].first;
            ll w = adj[u][i].second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
