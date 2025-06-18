#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(int node,vector<vector<int>>&lst , vector<int>&visited){
    queue<int>q;
    int temp;
    q.push(node);
    visited[node]=1;
    vector<int>component;
    component.push_back(node);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        int sz=lst[temp].size();

        for(int i=0;i<sz;i++){
            int nextnode;
            nextnode=lst[temp][i];
            if(!visited[nextnode]){
                visited[nextnode]=1;
                q.push(nextnode);
                component.push_back(nextnode);
            }
        }
    }
    return component;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>money(n);
        for(int i=0;i<n;i++){
            cin>>money[i];
        }
        vector<vector<int>>lst(n+1);
        vector<int>visited(n+1,0);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            lst[u].push_back(v);
            lst[v].push_back(u);
        }
        bool possible=true;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                vector<int>component=bfs(i,lst,visited);
                int sz2=component.size();
                int sum=0;
                for(int i=0;i<sz2;i++){
                    sum+=component[i];
                }
                  if(sum%sz2!=0){
                possible=false;
                break;
            }
            }

        }
        if(possible){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
