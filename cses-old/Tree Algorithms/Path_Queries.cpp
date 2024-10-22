#include <iostream>
#include <vector>

#define int long long 

using namespace std;
const int N = 2e5 + 1;

int n,q;
vector <int> a[N];
int maxdeep[N],heavy[N],par[N],v[N],head[N],pos[N];

void dfs1(int u,int p) {
    par[u] = p;
    int x = 0;
    for(auto v : a[u]) if (v != p) {
        dfs1(v,u);
        if (maxdeep[x] < maxdeep[v] + 1) x = v;
    }
    maxdeep[u] = maxdeep[x] + 1;
    heavy[u] = x;
}

void dfs2(int u,int p) {
    head[u] = p;
    pos[u] = ++pos[0];
    if (heavy[u]) dfs2(heavy[u],p);
    for(auto v: a[u]) if (v != par[u] && v != heavy[u]) dfs2(v,v);
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
        cin >> t >> s;
        if (t == 1) {
            cin >> x;
            upd(pos[s],x);
        } else {
            int sum = 0;
            while (s > 0) {
                sum += get(pos[head[s]],pos[s]);
                s = par[head[s]];
            }
            cout << sum << '\n';
        }
    }
    return 0;
}