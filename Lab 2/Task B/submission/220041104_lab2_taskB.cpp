#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

void pre()
{
    fastio;
}

void solve(int tc)
{
    int n, k, sum = 0;
    cin>>n>>k;
    n *= 2;
    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(), v.end());

    for(int i=0; i<n/2; i++){
        if(v[i + n/2] - v[i] < k){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
    }

    return 0;
}
