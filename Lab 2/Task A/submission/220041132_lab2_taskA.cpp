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

    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> y;
        v[i] = y;
    }

    sort(v.begin(), v.end(), greater<>());

    int sum = 0;
    int count = 0;

    for(int i = 0; i < n; ++i) {
        sum += v[i];
        ++count;
        if(sum >= x) break;
    }
    if(sum < x) {
        cout << "-1";  
    }else  {
        cout << count;
    }
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