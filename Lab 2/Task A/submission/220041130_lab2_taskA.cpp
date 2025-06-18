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

    vector<int> num;
    int y;
    for(int i=0; i<n; i++){
        cin >> y;
        num.push_back(y);
    }
    sort(num.begin(), num.end(), greater<>());
//    for(int i=0; i<n; i++){
//        cout << num[i] << " ";
//    }

    int sum = 0, res;
    for(int i=0; i<n; i++){
        sum += num[i];
//        cout << sum << " ";
        if(sum >= x) {
            res = i+1;
            break;
        }
    }
    if(sum >= x)
        cout << res;
    else
        cout << "-1";

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
