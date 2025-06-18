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
    int n, x;
    cin>> n>> x;
    vector<int> arr(2*n,0);
    for(int i=0; i<2*n; ++i)
    {
        cin>> arr[i]; 
    }
    sort(arr.begin(), arr.end());
    bool flag = true;
    for(int i=0; i<n; ++i)
    {
        if (!(arr[i+n] -arr[i] >= x ))
        {
            // flag = false;
            // break;
            cout<<"NO\n";
            return;
        }
    }
    // if(flag) cout<<"YES\n";
    // else cout<<"NO\n";
    cout<<"YES";
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