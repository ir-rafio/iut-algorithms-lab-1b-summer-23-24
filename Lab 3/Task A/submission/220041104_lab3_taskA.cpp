#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

vector <int> adj[1005];
vector<int> vis(1005, false);
int money[1005];
int sum = 0, cnt = 0;

void pre()
{
    fastio;
}

void dfs(int n){
    if(vis[n])
        return;

    sum += money[n];
    cnt++;
    vis[n] = true;

    for(auto p:adj[n])
        dfs(p);
}

void rewind(int n){
    for(int i=0; i<=n; i++){
        adj[i].clear();
        vis[i] = false;
        money[i] = 0;
    }
}

void solve(int tc)
{
    int n, m;
    cin>>n>>m;
    vector<int> v;

    rewind(n+3);

    for(int i=1; i<=n; i++)
        cin>>money[i];

    while(m--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        sum = 0;
        cnt = 0;

        if(vis[i])
            continue;

        dfs(i);

        if(sum % cnt == 0)
            v.push_back(sum/cnt);
        else
            v.push_back(-1);
    }

    for(int i=1; i<v.size(); i++){
        if(v[i] != v[i-1]){
            cout<<"Case "<<tc<<": No\n";
            return;
        }
    }

    for(auto p:v){
        if(p == -1){
            cout<<"Case "<<tc<<": No\n";
            return;
        }
    }

    cout<<"Case "<<tc<<": Yes\n";
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
