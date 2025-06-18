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

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.rbegin(), a.rend());

    int count = 0;
    LL sum = 0;

    for (int i = 0; i < n; i++) {
            sum += a[i];
            count++;
            if (sum >= x) {
                cout << count;
                break;
            }


    }
    if(sum<x) cout << -1;

    return;

}

signed main() {
    pre();

    int tt;
    cin >> tt;

    for (int tc = 1; tc <= tt; tc++) {
        solve(tc);
        cout << '\n';
    }

    return 0;
}
