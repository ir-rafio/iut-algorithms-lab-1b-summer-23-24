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
    int n, cnt = 1;
    cin>>n;
    vector<pair<int, int>> v(n);
    vector<int> time;

    for(int i=0; i<n; i++)
        cin>>v[i].second;
    for(int i=0; i<n; i++)
        cin>>v[i].first;

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
        swap(v[i].first, v[i].second);

    time.push_back(v[0].second);

    for(int i=1; i<n; i++){
        if(v[i].first >= time.back()){
            cnt++;
            time.push_back(v[i].second);
        }
    }

    cout<<cnt<<"\n";
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
