#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main() {
    fastio;
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> act(n);
        for (int i = 0; i < n; ++i) cin >> act[i].first;  
        for (int i = 0; i < n; ++i) cin >> act[i].second; 

    
        vector<pair<int, int>> sortedAct(n);
        for (int i = 0; i < n; ++i) {
            sortedAct[i] = {act[i].second, act[i].first};
        }

        sort(sortedAct.begin(), sortedAct.end());

        int count = 0;
        int last_end = 0;

        for (auto [end, start] : sortedAct) {
            if (start >= last_end) {
                count++;
                last_end = end;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
