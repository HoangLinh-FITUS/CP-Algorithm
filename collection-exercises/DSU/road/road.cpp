#include <iostream>
 
using namespace std;
const int N = 1e5 + 1;
 
int n,m;
int par[N],Rank[N];
int res1,res2;
 
int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}
 
void join(int x,int y) {
    int u = Find(x);
    int v = Find(y);
    if (u == v) return;
    if (u > v) swap(u,v);
    Rank[u] += Rank[v];
    res1--;
    res2 = max(res2,Rank[u]);
    par[v] = u;
}
 
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        Rank[i] = 1;
    }
    res1 = n;
    res2 = 1;
    while (m--) {
        int u,v;
        cin >> u >> v;
        join(u,v);
        cout << res1 << " " << res2 << '\n';
    }
    return 0;
}