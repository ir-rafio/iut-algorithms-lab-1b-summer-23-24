#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void solve(int tc) {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
   
    sort(a.begin(), a.end(), greater<int>());
    
    int sum = 0, count = 0;
    
   
    for (int i = 0; i < n; i++) {
        sum += a[i];
        count++;
        if (sum >= x) {
            break;
        }
    }
    
    
    if (sum >= x) {
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    fastio;

    int tt;
    cin >> tt;  

    for (int tc = 1; tc <= tt; tc++) {
        solve(tc);
    }

    return 0;
}

