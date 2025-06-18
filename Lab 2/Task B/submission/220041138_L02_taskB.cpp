#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, x;
    cin >> n >> x;
    vector<int> vec(2 * n);

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        if (vec[i + n] - vec[i] < x)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;

    return 0;
}

