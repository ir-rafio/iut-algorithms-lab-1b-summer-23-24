#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    bool arranged = true;

    vector<int> height(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> height[i];
    }

    sort(height.begin(), height.end());

    for (int i = 0; i < n; i++)
    {
        if (height[i + n] - height[i] < x)
        {
            arranged = false;
            break;
        }
    }

    cout << (arranged ? "YES" : "NO") << endl;

    return 0;
}