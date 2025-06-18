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

    vector<ll> v(2*n);

    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());

    ll i = n - 1, j = 2*n - 1;

    while (j >= 0 && i >= 0) {
        if (v[j] - v[i] < x) {
            cout << "NO" << endl;
            return;
        }
        j--;
        i--;
    } 

    cout  << "YES" << endl;

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
        // cout << '\n';
    }

    return 0;
}
