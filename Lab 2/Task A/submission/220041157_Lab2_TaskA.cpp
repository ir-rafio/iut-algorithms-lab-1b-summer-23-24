#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, a[200];

    cin >> t;

    while(t--)
    {
        int res = 0;
        cin >> n >> x;

        for(int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a + n);
        for(int q=n-1; q>=0; q--)

        {
            if(a[q] <= x)
            {
                x -= a[q];
                res++;
            }
            else if(x < 0)
            {
                x = 0;
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
