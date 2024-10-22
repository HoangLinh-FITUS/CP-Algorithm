#include <iostream>
#include <vector>

#define int long long 

using namespace std;
const int N = 2e5 + 1;

int n;
vector <int> a[N];
int Size[N],Sum[N];

void dfs(int u,int p = 0,int d = 0) {
    Size[u] = 1;
    Sum[u] = d;
    for(int v : a[u]) if (v != p) {
        dfs(v,u,d + 1);
        Sum[u] += Sum[v];
        Size[u] += Size[v];
    }
}

int res[N];

void dfs2(int u,int p = 0) {
    res[u] = Sum[u];
    for(auto v : a[u]) if (v != p) {
        int x = Sum[u],y = Size[u],z = Sum[v];
        Sum[u] -= Sum[v];
        Size[u] -= Size[v];
        Sum[v] += Sum[u] + n - 2*Size[v];
        dfs2(v,u);
        Sum[u] = x;
        Size[u] = y;
        Sum[v] = z;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    dfs2(1);
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}