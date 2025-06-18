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
    cin>>n >> x;
    vector<int> arr(n,0);
    for (int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());
    int sum =0;
    int count =0;
    for(int i=0; i<n; ++i)
    {
        if(sum>=x) break;
        sum += arr[i];
        count ++;
    }
    if(sum< x)
    {
        cout<<-1<<endl;
    }
    else cout<<count<<endl;


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