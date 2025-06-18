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
   int n, x, y;
   cin >> n >> x;
   
   vector<int> v(2*n);

    for(int i = 0; i < 2*n; ++i) {
        cin >> y;
        v[i] = y;
    }

    sort(v.begin(), v.end());

    int flag = 0;
    for(int i = 0; i < n; ++i) {
        if(v[i+n] - v[i] < x) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
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