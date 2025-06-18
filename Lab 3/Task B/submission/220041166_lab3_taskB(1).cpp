#include <bits/stdc++.h>
using namespace std;

// Simple union-find (disjoint set) structure
vector<int> parent, size;

// Find the root of an astronaut
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression for efficiency
    }
    return parent[x];
}

// Union of two astronauts, i.e., making them part of the same country
void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // Union by size: attach the smaller group to the larger one
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

int main() {
    int n, p;  // n = number of astronauts, p = number of pairs
    cin >> n >> p;

    // Initialize the parent and size arrays
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Initially, each astronaut is their own parent
    }

    // Read the pairs and union the astronauts in the same country
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    // Count the size of each connected component (group of astronauts from the same country)
    vector<int> group_sizes;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {  // This is the root of a connected component
            group_sizes.push_back(size[i]);
        }
    }

    // Calculate the total number of astronaut pairs
    long long total_pairs = (long long)n * (n - 1) / 2;

    // Calculate the number of invalid pairs (same country)
    long long invalid_pairs = 0;
    for (int size : group_sizes) {
        invalid_pairs += (long long)size * (size - 1) / 2;
    }

    // Valid pairs = total pairs - invalid pairs
    long long valid_pairs = total_pairs - invalid_pairs;

    // Output the result
    cout << valid_pairs << endl;

    return 0;
}

