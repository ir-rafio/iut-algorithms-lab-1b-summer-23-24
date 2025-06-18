#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;
}

void dfsHelper(int src, vector<int>& money, vector<vector<int>>& list, vector<bool>& visit, int& sum, int& total){
    visit[src] = true;
    sum += money[src];
    total++;

    for(int i=1; i<list[src].size(); i++){
        if(visit[i] == false)
           dfsHelper(list[src][i], money, list, visit, sum, total);
    }
}

bool dfs(int src, vector<int>& money, vector<vector<int>>& list, vector<bool>& visit){
    int sum=0, total=0;

    // save sum of money within connected group, and total number of people in group
    dfsHelper(src, money, list, visit, sum, total);

    // check if divisible
    if(sum%total == 0)
        return true;

    return false;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    vector<int> money(n+1);
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        money[i] = x;
    }

    vector<vector<int>> list(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    bool ans = 1;
    vector<bool> visit(n+1, false);
    for(int i=1; i<=n; i++){
        if(visit[i] == false)
            ans &= dfs(i, money, list, visit);
    }
    if(ans == 1)
        cout << "Yes";
    else
        cout << "No";
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
