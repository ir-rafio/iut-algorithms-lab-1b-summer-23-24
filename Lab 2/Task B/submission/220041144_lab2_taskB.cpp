#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int size = 2 * n;
    int ar[size];
    for (int i = 0; i < size; i++)
    {
        cin >> ar[i];
    }
    sort(ar, ar + size);
    for (int i = 0; i < n; i++)
    {
        if ( ar[i + n]-ar[i]  >= x)
            continue;
        else
        {
            cout << "NO" << endl;

            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}