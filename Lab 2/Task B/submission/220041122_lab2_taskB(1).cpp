#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void pre() {
    fastio;
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        if (a[n + i] - a[i] < x) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main() {
    pre();
    solve();
    return 0;
}

