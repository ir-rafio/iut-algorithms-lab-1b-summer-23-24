#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> h(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> h[i];
    }

    // Sort all heights
    sort(h.begin(), h.end());

    // Check the height condition for each corresponding person
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (h[i + n] - h[i] < x) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << endl;

    return 0;
}
