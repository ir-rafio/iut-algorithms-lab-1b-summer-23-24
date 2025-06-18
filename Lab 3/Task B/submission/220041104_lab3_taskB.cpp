#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

vector <int> adj[100005];
vector<int> vis(100005, false);
int sum = 0, cnt = 0;

void pre()
{
    fastio;
}

void dfs(int n){
    if(vis[n])
        return;

    cnt++;
    vis[n] = true;

    for(auto p:adj[n])
        dfs(p);
}

void solve(int tc)
{
    int n, m, res = 0;
    cin>>n>>m;
    vector<int> v;

    while(m--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sum = 0;

    for(int i=0; i<n; i++){
        cnt = 0;

        if(vis[i])
            continue;

        dfs(i);
        v.push_back(cnt);
        sum += cnt;
    }

    for(auto p:v){
        sum -= p;
        res += p*sum;
    }

    cout<<res<<"\n";
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
