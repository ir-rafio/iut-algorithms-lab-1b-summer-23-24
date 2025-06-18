#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;

vector<int> adj[N];
int visited[N] = {0};
int count[N];

void dfs(int node)
{
    visited[node] = 1;
    count[node]++;
    for (int i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i);
            count[node] += count[i];
        }
    }
}

int main()
{
    int n, p;
    cin >> n >> p;

    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    long long pairs = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            pairs += (long long)count[i] * (n - count[i]);
        }
    }

    cout << pairs / 2 << endl;

    return 0;
}