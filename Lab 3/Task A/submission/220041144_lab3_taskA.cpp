#include <iostream>
#include <vector>
using namespace std;

class DSU
{
    vector<int> parent, rank, sz;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
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
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return;
        if (rank[xr] < rank[yr])
        {
            parent[xr] = yr;
            sz[yr] += sz[xr];
        }
        else if (rank[xr] > rank[yr])
        {
            parent[yr] = xr;
            sz[xr] += sz[yr];
        }
        else
        {
            parent[yr] = xr;
            rank[xr]++;
            sz[xr] += sz[yr];
        }
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        DSU dsu(n);
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            dsu.unite(x, y);
        }
        vector<long long> group_sum(n, 0);
        vector<long long> group_size(n, 0);
        for (int i = 0; i < n; i++)
        {
            int st = dsu.find(i);
            group_sum[st] += v[i];
            group_size[st]++;
        }
        bool poss = true;
        int tg = -1;
        for (int i = 0; i < n; ++i)
        {
            if (group_size[i] == 0)
                continue;
            if (group_sum[i] % group_size[i] != 0)
            {
                poss = false;
                break;
            }
            int avg = group_sum[i] / group_size[i];
            if (tg == -1)
                tg = avg;
            else if (avg != tg)
            {
                poss = false;
                break;
            }
        }
                    cout << "Case " << i << ": " << (poss ? "Yes" : "No") << endl;

    }
    return 0;
}