#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;



void pre()
{
    fastio;

    
}

bool compare (pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve(int tc)
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);
    // for (auto [x, y] : v) {
    //     cout << x << " " << y << endl;
    // }

    ll cnt = 1;
        for (int i = 0, j = 1; i < n - 1 && j < n; j++) {
            if (v[j].first >= v[i].second) {
                cnt++;
                i = j;
                // cout << i << ' ' << j << endl;
            }
    }

    cout << cnt;

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
