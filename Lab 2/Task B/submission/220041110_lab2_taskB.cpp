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
    int n,x,c = 0;
    cin >> n >> x;
    int ar[2*n];

    for(int i=1; i<=2*n; i++)
        cin >> ar[i];

    sort(ar+1,ar+2*n+1);

    for(int i=1; i<=n; i++)
    {
        if(ar[i+n] - ar[i] >= x)
            c++;
        else
        {
            cout << "NO" << endl;
            break;
        }
    }
    if(c == n)
        cout << "YES" << endl;
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
