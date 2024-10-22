#include <iostream>
#include <vector>
#define int long long 

using namespace std;
const int N = 2e5 + 1;

vector <int> a[N];
int n,m;
int v[N],sum[N],S[N],E[N],pos[N];

void dfs(int u,int p) {
    S[u] = ++S[0];
    for(auto v : a[u]) if (v != p) dfs(v,u);
    E[u] = S[0];
}

int ST[N << 2];

void upd(int p,int val,int id = 1,int l = 1,int r = n) {
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) upd(p,val,id << 1,l,mid);
    else upd(p,val,id << 1 | 1,mid + 1,r);
    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int get(int u,int v,int id = 1,int l = 1,int r = n) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) >> 1;
    return get(u,v,id << 1,l,mid) + get(u,v,id << 1 | 1,mid + 1,r);
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1; i <= n; i++) upd(S[i],v[i]);
    while (m--) {
        int u,v,t;
        cin >> t >> u;
        if (t == 1) {
            cin >> v;
            upd(S[u],v);
        } else cout << get(S[u],E[u]) << '\n';
    }
    return 0;
}