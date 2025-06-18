#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre() {
    fastio;
}

void solve(int tc) {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n && sum < x; i++) {
        sum += min(arr[i], x - sum);
        count++;
    }
    if (sum == x) cout << count++;
    else cout << -1;
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