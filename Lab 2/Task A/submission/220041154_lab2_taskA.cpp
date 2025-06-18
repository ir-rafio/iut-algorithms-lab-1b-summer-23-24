#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n, x, c = 0;
    cin >> n >> x;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    lli ct = 0;
    for (lli i = 0; i < n; i++) {
        c += arr[i];
        if (c <= x)
            ct++;
    }
    if (c >= x)
        cout << ++ct << enl;
    else
        cout << -1 << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //