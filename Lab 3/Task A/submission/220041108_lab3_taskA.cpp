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
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<int>> graph(numNodes + 1);
    vector<int> nodeValue(numNodes + 1);
    vector<bool> visitedNodes(numNodes + 1, false);

    for(int i = 1; i <= numNodes; ++i) {
        cin >> nodeValue[i];
    }

    for(int i = 0; i < numEdges; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<float> componentAverages;

    for(int i = 1; i <= numNodes; ++i) {
        if(!visitedNodes[i]) {
            float componentSum = nodeValue[i]; 
            int componentSize = 1;

            queue<int> bfsQueue;
            bfsQueue.push(i);
            visitedNodes[i] = true;

            while(!bfsQueue.empty()) {
                int a = bfsQueue.front();
                bfsQueue.pop();
                
                for(auto neighbor : graph[a]) {
                    if(!visitedNodes[neighbor]) {
                        bfsQueue.push(neighbor);
                        visitedNodes[neighbor] = true;
                        componentSum += nodeValue[neighbor];
                        componentSize++;
                    }
                }      
            }

            float componentAvg = componentSum / componentSize;
            if(trunc(componentAvg) != componentAvg) {
                cout << "No" << endl;
                return;
            }
            componentAverages.push_back(componentAvg);
        }
    }

    int firstAvg = componentAverages.front();

    for(auto avg : componentAverages) {
        if(avg != firstAvg) {
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
