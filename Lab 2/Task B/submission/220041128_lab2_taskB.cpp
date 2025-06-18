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
    LL n, x;
    cin>>n>>x;

    LL arr[2*n],f[n],b[n];

    for(LL i=0; i<2*n; i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    for(LL i=0; i<n; i++)
    {
        f[i]=arr[i];
    }
    LL j=0;
    for(LL i=n; i<2*n; i++)
    {
        b[j]=arr[i];
        j++;
    }

    for(int i=0;i<n;i++)
    {
        if(abs(b[i]-f[i])<x)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;


}

signed main()
{
    pre();


    solve();




}
