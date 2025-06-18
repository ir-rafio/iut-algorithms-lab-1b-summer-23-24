#include <iostream>
#include <vector>
using namespace std;

class DSU
{
    vector<int> parent, sz;

public:
    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        int xr = find(x), yr = find(y);
        if (xr == yr)
            return;
        parent[yr] = xr;
        sz[xr] += sz[yr];
    }
    int size(int x)
    {
        return sz[find(x)];
    }
};
int main()
{
    int n, p;
    cin >> n >> p;
    DSU dsu(n);
    for (int i = 0; i < p; ++i)
    {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    vector<bool> counted(n, false);
    vector<int> group_sizes;
    for (int i = 0; i < n; ++i)
    {
        int st = dsu.find(i);
        if (!counted[st])
        {
            group_sizes.push_back(dsu.size(st));
            counted[st] = true;
        }
    }
    long long total = 0, sum = 0;
    for (int sz : group_sizes)
    {
        total += sum * sz;
        sum += sz;
    }
    cout << total << endl;
    return 0;
}