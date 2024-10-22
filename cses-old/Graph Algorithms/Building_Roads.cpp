#include <vector>
#include <iostream>

using namespace std;
const int N = 2e5 + 1;

int n,m;
int par[N],dd[N];

int Find(int u) {
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    while (m--) {
        int u,v;
        cin >> u >> v;
        u = Find(u);
        v = Find(v);
        if (u > v) swap(u,v);
        par[v] = u;
    }
    vector <int> res;
    for(int i = 1; i <= n; i++) if (dd[Find(i)] == 0) {
        res.push_back(Find(i));
        dd[res.back()] = 1;
    }
    cout << (int)res.size() - 1 << '\n';
    for(int i = 1; i < res.size(); i++) cout << res[0] << " " << res[i] << '\n';
    return 0;
}