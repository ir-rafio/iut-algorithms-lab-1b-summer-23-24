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
    LL n;cin>>n;
    vector<pair<LL,LL>>events(n);
    for(LL i=0;i<n;i++){
        cin>>events[i].second;
    }

    for(LL i=0;i<n;i++){
        cin>>events[i].first;
    }

    sort(events.begin(),events.end());

    vector<LL>time;
    time.push_back(events[0].first);
    LL ans=1;
    for(LL i=1;i<n;i++){
        if(events[i].second>time.back()){
            ans++;
            time.push_back(events[i].first);
        }
    }

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
