#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;



void pre()
{
    fastio;

    
}

void dfs (ll node, vector<vector<ll>>& adjList, vector<bool>& visited, ll& s, vector<ll>& money, ll& si) {
    if (visited[node]) {
        si++;
        return;
    }
    visited[node] = true;
    // cout << node << endl;
    s += money[node];
    for (auto v : adjList[node]) {
        if (!visited[v]) dfs(v, adjList, visited, s, money, si);
    }
    si++;
}

void solve(int tc)
{
    ll n, p;
    cin >> n >> p;
    vector<vector<ll>> adjList(n + 1);


    vector<ll> money(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> money[i];


    while (p--) {
        ll a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }


    vector<bool> visited(n + 1, 0);
    vector<ll> total(n + 1, 0);
    vector<ll> sizes(n + 1, 0);
    vector<ll> head;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            head.push_back(i);
            dfs(i, adjList, visited, total[i], money, sizes[i]);
        }
    }

    // for (auto i : total) cout << i << ' ';
    // cout << endl;

    // for (auto i : sizes) cout << i << ' ';
    // cout << endl;

    vector<ll> ans;
    for (int i = 0; i < head.size(); i++) {
        if (total[head[i]] % sizes[head[i]] != 0) {
            cout << "No";
            return;
        }
        else {
            ans.push_back(total[head[i]] / sizes[head[i]]);
        }
    }

    for (int i = 1; i < ans.size(); i++) {
        if(ans[i - 1] != ans[i]) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
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