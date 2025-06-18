#include<iostream>
#include<vector>
using namespace std;

void astronaut(int node, vector<vector<int>> &astro, vector<bool> &visited, int &count) {
    visited[node] = true;
    count++;
    for (int x : astro[node]) {
        if (!visited[x]) {
            astronaut(x,astro, visited, count);
        }
    }
}
int main(){
    int n,p;
    cin >> n >> p;

    vector<vector<int>>astro(n);
    for(int i=0;i<p ;i++){
        int u, v;
        cin >> u >> v;
        astro[u].push_back(v);
        astro[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    vector<int>size;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int count = 0;
            astronaut(i, astro, visited, count);
            size.push_back(count);
        }
    }

    long long pairs = (long long)n * (n - 1) / 2;
    long long samePairs = 0;
    for (int size : size) {
        samePairs += (long long)size * (size - 1) / 2;
    }

    cout << (pairs - samePairs) << "\n";

    return 0;
}
