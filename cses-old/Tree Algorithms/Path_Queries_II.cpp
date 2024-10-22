#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

using namespace std;
const int N = 3e5 + 1;

int n,q;
vector <int> a[N];
int heavy[N],par[N],v[N],head[N],pos[N],deep[N];

int dfs1(int u,int p) {
    par[u] = p;
    int Size = 1,Max = 0;
    for(auto v : a[u]) if (v != p) {
        deep[v] = deep[u] + 1;
        int z = dfs1(v,u);
        Size += z;
        if (Max < z) {
            Max = z;
            heavy[u] = v;
        }
    }
    return Size;
}

void dfs2(int u,int p) {
    head[u] = p;
    pos[u] = ++pos[0];
    if (heavy[u]) dfs2(heavy[u],p);
    for(auto v: a[u]) if (v != par[u] && v != heavy[u]) dfs2(v,v);
}

int ST[N << 1];

void upd(int p,int val) {
    p--;
    for(ST[p += n] = val; p > 1; p >>= 1) ST[p >> 1] = max(ST[p],ST[p ^ 1]);
}

int get(int l,int r) {
    l--;
    int res = 0;
    for(l += n,r += n; l < r; l >>= 1,r >>= 1) {
        if (l & 1) res = max(res,ST[l++]);
        if (r & 1) res = max(res,ST[--r]);
    }
    return res;
}

int getMax(int u,int v) {
    int res = 0;
    for(; head[u] != head[v]; v = par[head[v]]) {
        if (deep[head[u]] > deep[head[v]]) swap(u,v);
        res = max(res,get(pos[head[v]],pos[v]));
    }
    if (deep[u] > deep[v]) swap(u,v);
    return max(res,get(pos[u],pos[v]));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i = 1; i <= n; i++) upd(pos[i],v[i]);
    while (q--) {
        int s,x,t;
        cin >> t >> s >> x;
        if (t == 1) upd(pos[s],x); 
        else cout << getMax(s,x) << '\n';
    }
    return 0;
}