#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 1;

int n,m;
vector <pair<int,pair<int,int>>> e;
int par[N];

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        e.push_back({w,{u,v}});
    }
    sort(e.begin(),e.end());
    long long res = 0;
    for(auto i: e) {
        int w = i.first;
        int u = i.second.first;
        int v = i.second.second;
        u = Find(u);
        v = Find(v);
        if (u == v) continue;
        res += w;     
        if (u > v) swap(u,v);
        par[v] = u;
    }
    for(int i = 2; i <= n; i++) if (Find(i) != Find(1)) return cout << "IMPOSSIBLE",0;
    cout << res;
    return 0;
}