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
    int n,x;
    cin>>n>>x;
    vector<int>a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    bool yes=true;
    for(int i=0;i<n;i++){
        if(a[i+n]-a[i]<x){
            yes=false;
            break;
        }
    }
    if(yes) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;
    
    // for(tc = 1; tc <= tt; tc++)
    // {
        // cout << "Case " << tc << ": ";
        solve(tc);
        // cout << '\n';
    // }

    return 0;
}