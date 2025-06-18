#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;



void pre()
{
    fastio;

    
}

void dfs (ll node, vector<vector<ll>>& adjList, vector<bool>& visited, ll& s) {
    if (visited[node]) {
        s++;
        return;
    }
    visited[node] = true;
    // cout << node << endl;
    for (auto v : adjList[node]) {
        if (!visited[v]) dfs(v, adjList, visited, s);
    }
    s++;
}

void solve(int tc)
{
    ll n, p;
    cin >> n >> p;
    vector<vector<ll>> adjList(n + 1);

    while (p--) {
        ll a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(n + 1, 0);
    vector<ll> sizes(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, adjList, visited, sizes[i]);
    }

    // for (auto i : sizes) cout << i << ' ';

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + sizes[i - 1];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += sizes[i] * (pref[n] - pref[i + 1]);
    }

    cout << ans << endl;
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