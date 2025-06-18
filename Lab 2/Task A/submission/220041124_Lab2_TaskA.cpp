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

LL n,x,total=0,ans=0;
        cin>>n>>x;
        vector<LL>v(n);
        for(auto &i:v)cin>>i;
        sort(v.rbegin(),v.rend());
        for(LL i=0;i<n;i++){
            total+=v[i];
            ans++;
            if(total>=x)break;
        }
        if(total<x)ans=-1;
        cout<<ans<<"\n";
    
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
