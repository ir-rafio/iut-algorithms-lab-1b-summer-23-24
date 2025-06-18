#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre() {
    fastio;
}

void solve(int tc) {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    for (int i = 0; i < n; i++) cin >> arr[i].first;

    sort(arr.begin(), arr.end());

    int count = 0;
    int last_end = -1;

    for (pair<int, int> p : arr) {
        int end = p.first;
        int start = p.second;

        if (start >= last_end) {
            count++;
            last_end = end;
        }
    }
    cout << count << "\n";
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