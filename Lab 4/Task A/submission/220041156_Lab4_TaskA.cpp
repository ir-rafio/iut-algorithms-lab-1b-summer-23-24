#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 100000;

vector<pair<int, int>> graph[MAX];
long long dist[MAX];

int main(){
    int n, m;
    bool visited[MAX] = {false};

    cin >> n>>m;

    for (int i=0;i< m;i++) {
        int a, b, c;
        cin >> a>>b>>c;
        graph[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> queue;

    dist[1] = 0;
    queue.push({0, 1});

    while (!queue.empty()){

        auto [currDist, u] = queue.top();
        queue.pop();

        if (currDist > dist[u]) continue;

        for (auto [v, cost] : graph[u]) {
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                queue.push({dist[v], v});
        }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

return 0;
}
