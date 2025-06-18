#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void dfsHelper(int src, vector<vector<int>>& list, vector<bool>& visit, int& total){
    visit[src] = true;
    total++;

    for(int i=0; i<list[src].size(); i++){
        if(visit[i] == false)
           dfsHelper(list[src][i], list, visit, total);
    }
}

int dfs(int src, vector<vector<int>>& list, vector<bool>& visit){
    int total=0;
    dfsHelper(src, list, visit, total);
    //cout<< total <<" ";
    return total;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> list(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    vector<bool> visit(n, false);
    vector<int> compSize;
    for(int i=0; i<n; i++){
        if(visit[i] == false){
            compSize.push_back(dfs(i, list, visit));
        }
    }
//    for(int i:compSize)
//        cout << i<<" " ;
}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
