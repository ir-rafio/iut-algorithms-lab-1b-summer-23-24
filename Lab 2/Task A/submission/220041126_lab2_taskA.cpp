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
        cin >> n >> x;
        vector<int> v;
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            v.push_back(val);
        }
        sort(v.begin(), v.end(), greater<int>());
        int count = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += v[i];
            count++;
            if(sum >= x){
                break;
            }
        }
        (sum < x) ? cout << -1 : cout << count;
        v.clear();
    
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
