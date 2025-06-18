#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

/*3 4
1 2 6
1 3 2
3 2 3
1 3 4*/

vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& adjList){
    int n = adjList.size();

    // distance array
    vector<int> distance(n, 99999);

    // priority queue in descending order, {dist, val}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, src});
    distance[src] = 0;

    while(!pq.empty()){
        pair<int, int> u = pq.top();
        pq.pop();
        cout << "->" << u.first << ", " << u.second << endl;

        int curr = u.first;

        for(auto x : adjList[u.first]){
            // first = value, second = weight
            int val = x.first, weight = x.second;

            if(distance[curr] + weight < distance[val])
            {
                distance[val] = distance[curr] + weight;
                pq.push({distance[val], val});
            }

        }
    }
    return distance;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adjList(n);

    for(int i=0; i<m; i++){
        int a, b, dist;
        cin >> a >> b >> dist;

        adjList[a-1].push_back({b-1, dist});
    }



    vector<int> res = dijkstra(0, adjList);
    for(int x : res){
        cout << x << " ";
    }

}



signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
