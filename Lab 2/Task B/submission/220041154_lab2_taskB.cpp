#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n, x;
    cin >> n >> x;
    lli p = 2 * n;
    vector<lli> arr(p);
    for (lli i = 0; i < p; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<lli> st(n), tl(n);
    for (lli i = 0; i < n; i++) st[i] = arr[i];
    for (lli i = n; i < p; i++) tl[i - n] = arr[i];
    for (lli i = n - 1; i >= 0; i--) {
        lli k = arr[i] + x;
        auto lb = lower_bound(tl.begin(), tl.end(), k);
        if (lb == tl.end()) {
            cout << "NO" << enl;
            return;
        } else {
            st.pop_back();
            lli ix = lb - tl.begin();
            tl.erase(tl.begin() + ix);
        }
    }
    if (st.size() == 0 && tl.size() == 0)
        cout << "YES" << enl;
    else
        cout << "NO" << enl;
}
int main() {
    fast();
    lli t = 1;
    //  cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //