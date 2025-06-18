#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n;
    cin >> n;
    vector<lli> sd(n), fd(n);
    vector<pair<lli, lli>> dates(n);
    for (lli i = 0; i < n; i++) cin >> sd[i];
    for (lli i = 0; i < n; i++) cin >> fd[i];
    // first value of pair -> starting date
    // second value of pair -> finishing date
    for (lli i = 0; i < n; i++) {
        dates[i].first = sd[i];
        dates[i].second = fd[i];
    }
    sort(dates.begin(), dates.end(), [](pair<lli, lli> a, pair<lli, lli> b) {
        return a.second < b.second;
    });
    lli ct = 0, l = 0, r = 0;
    for (lli i = 0; i < n; i++) {
        if (i == 0)
            ct++, r++;
        else {
            if (dates[r].first > dates[l].second) {
                ct++;
                l = i, r = i + 1;
            } else {
                r++;
            }
        }
    }
    cout << ct << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //