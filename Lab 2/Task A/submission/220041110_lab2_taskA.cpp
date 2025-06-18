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
    int t,n,x,sum=0,c = 0;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n >> x;
        int ar[n];
        for(int j=0; j<n; j++)
            cin >> ar[j];

        sort(ar,ar+n, greater<>());

        for(int j=0; j<n; j++)
        {
            if(sum >= x)
                break;
            sum +=ar[j];
            c++;
        }
        if(sum < x)
        {
            c = -1;
            cout << c << endl;
        }
        else
            cout << c << endl;
        c = 0;
        sum = 0;
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
