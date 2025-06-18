#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100000 + 5;
int parent_[MAXN], sz[MAXN];

int findp(int u) {
    return parent_[u] == u ? u : parent_[u] = findp(parent_[u]);
}

void unite(int a, int b) {
    a = findp(a);
    b = findp(b);

        if (sz[a] < sz[b]) swap(a, b);
        parent_[b] = a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;


    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }

    long long ans = 0, sum = 0;
    for (long long s : comps) {

    }

    cout << ans << "\n";
    return 0;
}
