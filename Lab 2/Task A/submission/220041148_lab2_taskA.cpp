#include <bits/stdc++.h>
using namespace std;




void process() {
    int size;
    int limit;
    cin >> size >> limit;

    vector<int> values(size);
    for (int &v : values) cin >> v;

    sort(values.begin(), values.end(), greater<int>());

    int sum = 0;
    int count = 0;

    for (int idx = 0; idx < size; ++idx) {
        sum += values[idx];
        if (sum <= limit)
            count++;
    }

    if (sum > limit)
        cout << count + 1 << endl;
    else
        cout << -1 << endl;
}

int main() {
   

    int testCases;
    cin >> testCases;

    while (testCases--) {
        process();
    }

    return 0;
}
