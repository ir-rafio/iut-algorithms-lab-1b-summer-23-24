#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(2 * n);
    
    for (int i = 0; i < 2 * n; ++i) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    
    for (int i = 0; i < n; ++i) {
        if (h[n + i] < h[i] + x) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
