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
    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.rbegin(), v.rend());

    for(int i=0; i<n; i++){
        sum += v[i];

        if(sum >= k){
            cout<<i+1<<"\n";
            return;
        }
    }

    cout<<"-1\n";
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
    }

    return 0;
}
