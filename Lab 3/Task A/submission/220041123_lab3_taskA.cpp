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
    int n, m;
    cin >> n >> m;
    vector< vector< int > > adjList(n + 1);
    vector<int> money(n+1);
    vector<bool> visited(n+1, false);

    for(int i = 1; i <= n; ++i) {
        cin >> money[i];
    }

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<float> avgs;


    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            float sum = money[i]; 
            int count = 1;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                for(auto el : adjList[u]) {
                    if(!visited[el]) {
                        q.push(el);
                        visited[el] = true;
                        sum += money[el];
                        count++;
                    }
                }      
            }

            float avg = sum / count;
                if(trunc(avg) != avg) {
                    cout << "No" << endl;
                    return;
                }
                avgs.push_back(avg);
        }
    }

    // Solution check 
   int in = avgs.front();

    for(auto el : avgs) {
        if(el != in) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}