#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
const ll MAX = 1e18;

struct State
{
    ll time;
    int city;
    int speed;
    bool operator>(const State &other) const
    {
        return time > other.time;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> s(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> s[i];

    vector<vector<ll>> dist(n + 1, vector<ll>(1001, MAX));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[1][s[1]] = 0;
    pq.push({0, 1, s[1]});

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        ll cur_time = current.time;
        int u = current.city;
        int speed = current.speed;

        if (cur_time > dist[u][speed])
            continue;

        
        int new_speed = s[u];
        if (cur_time < dist[u][new_speed])
        {
            dist[u][new_speed] = cur_time;
            pq.push({cur_time, u, new_speed});
        }

       
        for (int i = 0; i <graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            ll next_time = cur_time + 1LL * w * speed;
            if (next_time < dist[v][speed])
            {
                dist[v][speed] = next_time;
                pq.push({next_time, v, speed});
            }
        }
    }

    ll ans = MAX;
    for (int spd = 1; spd <= 1000; spd++)
    {
        ans = min(ans, dist[n][spd]);
    }
    cout << ans << "\n";
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
