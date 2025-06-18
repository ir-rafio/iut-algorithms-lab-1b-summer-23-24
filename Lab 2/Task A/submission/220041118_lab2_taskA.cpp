#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;



void pre()
{
    fastio;

    
}

void solve(int tc)
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto& i : v) cin >> i;

    sort(v.rbegin(), v.rend());

    ll cnt = 0, sum = 0, i = 0, j = n - 1;

    for (int i = 0; i < n && sum <= x ; i++) {
        cnt++;
        sum += v[i];
    }

    if (sum < x) {
        cout << -1;
        return;
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