#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main() {
    fastio;
    
    int n, x;
    cin >> n >> x;

    vector<int> h(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (h[i + n] < h[i] + x) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << '\n';

    return 0;
}
