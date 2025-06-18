#include <bits/stdc++.h>
using namespace std;


vector<int> parent, size;


int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); 
    }
    return parent[x];
}


void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

int main() {
    int n, p;  
    cin >> n >> p;

    
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;  

   
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    
    vector<int> group_sizes;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {  
            group_sizes.push_back(size[i]);
        }
    }

    
    long long total_pairs = (long long)n * (n - 1) / 2;

    
    long long invalid_pairs = 0;
    for (int size : group_sizes) {
        invalid_pairs += (long long)size * (size - 1) / 2;
    }

    
    long long valid_pairs = total_pairs - invalid_pairs;

    
    cout << valid_pairs << endl;

    return 0;
}

