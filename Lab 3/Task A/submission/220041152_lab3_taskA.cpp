#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1005;

int n, m;
int money[MAX_N];
vector<int> adj[MAX_N];
int case_num = 0;

bool bfs(int node)
{
    queue<int> q;
    q.push(node);
    long long sum = 0;
    int count = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        sum += money[u];
        count++;
        money[u] = 1;

        for (int v : adj[u])
        {
            if (money[v] != 1)
            {
                q.push(v);
            }
        }
    }

    return sum % count == 0;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            cin >> money[i];
            adj[i].clear();
        }

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool valid = true;
        long long total_sum = 0;

        for (int i = 1; i <= n; i++)
        {
            total_sum += money[i];
        }

        if (total_sum % n != 0)
        {
            valid = false;
        }
        else
        {
            int target = total_sum / n;

            for (int i = 1; i <= n; i++)
            {
                if (money[i] != -1)
                {
                    if (!bfs(i))
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }

        cout << "Case " << ++case_num << ": " << (valid ? "Yes" : "No") << endl;

        for (int i = 1; i <= n; i++)
        {
            money[i] = 0;
        }
    }

    return 0;
}