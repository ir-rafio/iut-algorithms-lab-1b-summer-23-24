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
    vector<int>start(n),end(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(end[j]<end[i]){
                swap(end[i],end[j]);
                swap(start[i],start[j]);
            }
        }
    }
//     for(int i=0;i<n;i++){
//         cout<<start[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<n;i++){
//         cout<<end[i]<<" ";
//     }
// cout<<endl;
    
}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}