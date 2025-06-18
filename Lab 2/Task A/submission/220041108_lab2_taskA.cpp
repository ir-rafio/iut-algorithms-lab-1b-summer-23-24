#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void solve(int tc)
{
    int x, n;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &&i : v)
    {
        cin >> i;
    }
    sort(v.rbegin(), v.rend());
    int counter = 0;
    for (int i = 0; i < n  && x > 0; i++)
    {
            x -= v[i];
            counter++;
    }
    if(x > 0)
    cout << -1 << endl;
    else
    cout << counter << endl;
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
