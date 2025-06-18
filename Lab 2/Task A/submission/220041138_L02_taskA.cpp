#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> vec(n);
        int sum = 0, sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            sum2 += vec[i];
        }
        sort(vec.begin(), vec.end());
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum1 = sum;
            sum += vec[i];
            if (sum <= x)
            {
                count++;
            }
        }
        if (sum2 < x)
        {
            count = -1;
            cout << count << endl;
        }
        else if (sum1 == x)
        {
            cout << count << endl;
        }
        else
        {
            cout << count + 1 << endl;
        }
    }
    return 0;
}

