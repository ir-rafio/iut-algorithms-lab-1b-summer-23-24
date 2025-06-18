#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> time(n);

        for (int i = 0; i < n; i++)
            cin >> time[i].second;

        for (int i = 0; i < n; i++)
            cin >> time[i].first;

        sort(time.begin(), time.end());

        int count = 1;
        int End = time[0].first;

        for (int i = 1; i < n; i++)
        {
            if (time[i].second >= End)
            {
                count++;
                End = time[i].first;
            }
        }

        cout << count << endl;
    }

    return 0;
}