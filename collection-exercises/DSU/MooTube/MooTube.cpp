#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 1;

int n, q;
vector < pair<int, pair<int, int>> > edge, Query;
int par[N], Rank[N]; 
int ans[N];

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

void Join(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x > y) swap(x, y);
    Rank[x] += Rank[y];
    par[y] = x;
}

int main() {
    freopen("mootube.in", "r", stdin); 
    freopen("mootube.out", "w", stdout);

    ios::sync_with_stdio(false);cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) par[i] = i, Rank[i] = 1;

    for (int i = 1; i < n; i++) {
        int u, v, r;
        cin >> u >> v >> r;
        edge.push_back({ r, {u, v} });
    }
    sort(edge.begin(), edge.end());
    reverse(edge.begin(), edge.end());
  
    // Truy Van 
    for (int i = 1; i <= q; i++) {
        int k, v;
        cin >> k >> v;
        Query.push_back({ k, {v, i} });
    }
    sort(Query.begin(), Query.end());
    reverse(Query.begin(), Query.end());

    // Tao Cay 
    int j = 0;
    for (const auto& qi: Query) {
        int v = qi.second.first;
        int id = qi.second.second;
        int k = qi.first;

        while (j < edge.size() && edge[j].first >= k) {
            Join(edge[j].second.first, edge[j].second.second);
            j++;
        }

        ans[id] = Rank[Find(v)] - 1;
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
 
    return 0;
}