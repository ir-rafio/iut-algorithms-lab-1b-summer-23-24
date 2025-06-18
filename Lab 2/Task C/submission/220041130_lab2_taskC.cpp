#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void selectionSort (int arr[][2], int n) {
    for (int i=0; i<n; i++)
    {
        int min = i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j][1] < arr[min][1])
                min = j;
        }
        swap(arr[i][0], arr[min][0]);
        swap(arr[i][1], arr[min][1]);
    }
}

void solve(int tc)
{
    int n;
    cin >> n;

    int time[n][2];
    for(int i=0; i<n; i++){
        cin >>time[i][0];
    }
    for(int i=0; i<n; i++){
        cin >> time[i][1];
    }

    // sort wrt end times
    selectionSort(time, n);
    int count;
    for(int i=0; i<n-1; i++){
        // which end times are less than next begin times
        if(time[i][1] <= time[i+1][0])
            count++;
    }
    cout << "->" << count << endl;

}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
