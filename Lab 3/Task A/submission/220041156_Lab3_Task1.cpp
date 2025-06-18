#include <iostream>
#include <vector>
using namespace std;

void dfs(int astraunot, vector<vector<int>>& graph,vector<bool>& visited,int& count){

    visited[astraunot]=true;
    count++;

    for(int neighbour : graph[astraunot]){
        if(!visited[neighbour])
        {
            dfs(neighbour,graph,visited,count);
        }
    }

}

int main(){
    int n,p;

    cin>>n>>p;
    vector <vector<int>>graph(n);

    for(int i=0; i<p ;i++){
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    vector<bool> visited(n,false);
    vector<int> csize;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            int count = 0;
            dfs(i,graph,visited,count);
            csize.push_back(count);
        }
    }

    long totalways =0;
    long sum=0;

    for(int size:csize){
        totalways+= size*sum;
        sum+=size;
    }
    cout<<totalways;


return 0;

}
