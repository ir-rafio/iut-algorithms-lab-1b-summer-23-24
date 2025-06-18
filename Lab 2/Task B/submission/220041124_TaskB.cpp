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
    LL n,x;cin>>n>>x;

    vector<LL>v(2*n);
    for(auto &i:v)cin>>i;
    sort(v.begin(),v.end());
    LL j=n;
    for(LL i=0;i<n;i++,j++){
        LL dif=v[j]-v[i];
        if(dif<x){
            cout<<"NO\n";
            return ;
        }
    }

    cout<<"YES\n";
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
