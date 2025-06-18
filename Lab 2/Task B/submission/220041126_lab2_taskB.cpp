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
    int n, diff, flag = 1;
    cin >> n >> diff;
    vector<int> heights;
    for(int i=0; i<2*n; i++){
    	int val;
    	cin >> val;
    	heights.push_back(val);
    }
    sort(heights.begin(), heights.end());
    cout << endl;
    for(int i=0; i<n; i++){
    	if(abs(heights[i]-heights[(n-i)])<diff){
    	    //cout << "val1 : " << i << " val2: " << (n-1) << endl;
    		flag = 0;
    		break;	
    	}
    }
    if(flag == 0){
        cout << "NO";
    }else{
        cout << "YES";
    }
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
        // cout << '\n';
    }

    return 0;
}
