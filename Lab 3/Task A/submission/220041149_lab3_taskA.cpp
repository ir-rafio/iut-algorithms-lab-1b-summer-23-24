#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}
bool canBedistributed(vector<vector<int>>& adjl, int vert, vector<int>& money)
{
    vector<bool>visited(vert, false);
    vector<int> sum;
    vector<int>size;
    for(int i=0; i<vert; ++i)
    {
        if(!visited[i])
        {
            queue<int> q;
            vector<int> component;

            visited[i] = true;
            q.push(i);
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                component.push_back(temp);
                int sz = adjl[temp].size();
                for(int k=0; k<sz; ++k)
                {
                    int next = adjl[temp][k];
                    if(!visited[next])
                    {
                       visited[next] = true;
                       q.push(next);

                    }
                }
            }
            LL total_money = 0;
            for(int person: component)
            {
                total_money += money[person];
            }
            if(total_money% component.size() != 0) return false;
            sum.push_back(total_money);
            size.push_back(component.size());
        }
    }
    for (int i = 0; i < sum.size() - 1; ++i)
    {
        if (sum[i]/size[i] != sum[i + 1]/size[i+1])
        {
            
            
            return false;
        }
    }
    return true;
}

void solve(int tc)
{
    int vert , edges;
    cin>>vert>> edges;
    vector<int> money;
    money.resize(vert);
    vector<vector<int>> adjl;
    adjl.resize(vert);
    for (int i=0; i<vert; ++i)
    {
        cin>>money[i];
    }

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        --u; --v;
        adjl[u].push_back(v);
    }
    bool canbe = canBedistributed(adjl, vert, money);
    if(canbe ) cout<<"Yes";
    else cout<<"No";
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}


/*
3
5 4
1 0 1 1 2
1 2
2 3
3 4
4 5
2 1
5 10
1 2
4 2
1 1 0 2
1 2
2 3

*/