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
    int n;
    cin>>n;
    vector<int> s(n);
    vector<int> e(n);
    for(int i=0; i< n; ++i)
    {
        cin>>s[i];
    }
    for(int i=0; i< n; ++i)
    {
        cin>>e[i];
    }
    vector<pair<int, int>> time;
    time.reserve(n);
    for(int i=0; i<n ; ++i)
    {
        time.push_back({s[i], e[i]});
    }
    sort(time.begin(), time.end(), [](pair<int, int> & a, pair<int , int> &b){
        return a.second< b.second;});

    int count =0;
    int prev = 0;

    for(int i=0; i<n; ++i)
    {
        if(time[i].first >= prev) 
        {
            count++;
            prev = time[i].second;

        }
    }
    cout<<count<<endl;
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