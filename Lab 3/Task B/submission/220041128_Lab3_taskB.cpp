#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

const int MAX= 1e5 + 5;
vector<vector<int>>adj(MAX);
bool visited[MAX];


int dfs(int node)
{
    visited[node]= true;
    int size=1;

    for(int neighbor: adj[node])
    {
        if(!visited[neighbor])
        {
            size+= dfs(neighbor);
        }
    }

    return size;
}

int main()
{
    int n,p;
    cin>>n>>p;

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }

    for(int i=0;i<p;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>group;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            int size= dfs(i);
            group.push_back(size);
        }
    }

    long long int total = 1LL * n * (n - 1) / 2;

    for (int size : group) 
    {
        total -= 1LL * size * (size - 1) / 2;
    }

    cout<<total<<endl;


}