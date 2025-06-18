#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
using LL = long long;

void pre()
{
    fastio;
}

void solve(int tc)
{
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> bottles(n);
        for (int i = 0; i < n; i++)
            cin >> bottles[i];

        sort(bottles.rbegin(), bottles.rend());

        int count = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += bottles[i];
            count++;
            if (sum >= x)
            {
                cout << count << endl;
                break;
            }
        }

        if (sum < x)
            cout << -1 << endl;
    }

    return 0;
}