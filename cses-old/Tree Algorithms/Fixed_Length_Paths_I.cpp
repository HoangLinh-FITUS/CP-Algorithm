#include <iostream>
#include <vector>
#pragma GCC optimize("O2")

using namespace std;
const int N = 2e5 + 1;

int n,k;
vector <int> a[N];
bool dd[N];
long long res = 0;
int Size[N],cnt[N];

int sizeTree(int u,int p = -1) {
    Size[u] = 1;
    for(auto v : a[u]) if (v != p && !dd[v]) Size[u] += sizeTree(v,u);
    return Size[u];
}

int centroid(int u,int tree_size,int p = -1) {
    for(int v: a[u]) if (v != p && !dd[v] && Size[v] >= tree_size) return centroid(v,tree_size,u);
    return u;
}

int maxdeep = 0;

void calc(int u,int p,bool fill,int d = 1) {
    if (d > k) return;
    maxdeep = max(maxdeep,d);
    if (fill) cnt[d]++; else res += cnt[k - d];
    for(auto v: a[u]) if (v != p && !dd[v]) calc(v,u,fill,d + 1);
}

void dfs(int u) {
    int x = centroid(u,sizeTree(u) >> 1);
    dd[x] = 1;
    maxdeep = 0;
    for(auto v: a[x]) if (!dd[v]) {
        calc(v,x,false);
        calc(v,x,true);
    }
    for(int i = 1; i <= maxdeep; i++) cnt[i] = 0;
    for(auto v : a[x]) if (!dd[v]) dfs(v);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    cnt[0] = 1;
    dfs(1);
    cout << res;
    return 0;
}