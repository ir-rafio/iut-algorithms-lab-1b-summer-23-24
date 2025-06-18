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

bool comp(int a, int b)
{
    return a>b;
}



void solve()
{
    int n;
    LL x;
    cin>>n>>x;

    vector<LL> arr(n);

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr.rbegin(),arr.rend());


    int count= 0;
    for (int i = 0; i < n; i++)
    {
        if (x == 0)
            break;
        LL rem = min(arr[i], x);
        x -= rem;
        count++;
    }

    if(x==0)
            cout<<count<<endl;
    else
            cout<<"-1"<<endl;

}

signed main()
{
    pre();

    LL t;
    cin>>t;

    for(LL i=0; i<t; i++)
    {
        solve();
    }



}
