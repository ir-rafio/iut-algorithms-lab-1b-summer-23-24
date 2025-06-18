#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> s(n);
    vector<int> e(n);
    vector<pair<int, int>> times(n);

    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> e[i];
        times[i].first = s[i];
        times[i].second = e[i];
    }

    if (n == 0) {
        cout << 0;
        return;
    }

    sort(times.begin(), times.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    });

    int pe = times[0].second;
    int count = 1;
    for(int i = 1; i < n; ++i) {
        if(times[i].first >= pe) {
            ++count;
            pe = times[i].second;
        }
    }

    cout << count;
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

//  5
//  4
//  0 5 1 3
//  6 7 2 4
//  3
//  1 4 6
//  5 7 10
//  6
//  3 8 2 1 5 3
//  9 9 5 4 9 6
//  5
//  1 2 3 1 4
//  10 10 5 2 5
//  3
//  1 6 4
//  5 10 7