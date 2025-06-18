#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int solve(vector<int>& bottles, int x) {
    sort(bottles.rbegin(), bottles.rend()); 

    int used = 0;
    for (int i = 0; i < bottles.size(); ++i) {
        if (x == 0) break;
        int take = min(bottles[i], x); 
        x -= take;
        used++;
    }

    return x == 0 ? used : -1;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> bottles(n);
        for (int i = 0; i < n; ++i) {
            cin >> bottles[i];
        }

        int result = solve(bottles, x);
        cout << result << '\n';
    }

    return 0;
}
