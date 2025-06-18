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
    int n, p;
    cin >> n >> p;

    vector< vector<int> > adjList(n);
    vector<bool> visited(n, false);

    for(int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<long long> combs;

    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {

            queue<int> q;
            q.push(i);
            visited[i] = true;

            int count = 1;
            
            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(auto el : adjList[u]) {
                    if(!visited[el]) {
                        q.push(el);
                        visited[el] = true;
                        count++;
                    }
                }
            }

            combs.push_back(count * (count - 1) / 2);
        }
    }

    long long CombCount = 0;
    for(auto el : combs) {
        CombCount += el;
    }

    cout << 1LL * n * (n-1) / 2 - CombCount << endl; 
}


signed main()
{
    pre();

    // int tc, tt = 1;
    // cin >> tt;
    
    // for(tc = 1; tc <= tt; tc++)
    // {
    //     // cout << "Case " << tc << ": ";
    //     solve(tc);
    //     cout << '\n';
    // }

    solve(1);

    return 0;
}

