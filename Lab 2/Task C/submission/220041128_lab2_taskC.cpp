#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}




void solve()
{
    LL n;
    cin>>n;
    LL s[n],e[n];
    for(LL i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(LL i=0;i<n;i++)
    {
        cin>>e[i];
    }

    vector<pair<int,int>>p;

    for(int i=0;i<n;i++)
    {
        p.push_back({e[i],s[i]});
    }

    sort(p.begin(),p.end());

    LL count=0;
    LL last=0;

    for(auto [e,s]: p)
    {
        if(s>=last)
        {
            count++;
            last= e;
        }
    }

    cout<<count<<endl;

}

signed main()
{
    pre();

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       solve();
    }





}
