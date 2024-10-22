#include <iostream>
#define int long long 

using namespace std;
const int N = 2e5 + 1;

int ST[4 * N];
int lazy[4 * N];
int n,q;
int a[N];

void down(int id,int l,int r) {
    if (lazy[id]) {
        ST[id] += (r - l + 1) * lazy[id];
        if (l != r) {
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}
void upd(int u,int v,int val,int id = 1,int l = 1,int r = n) {
    down(id,l,r);
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        lazy[id] += val;
        down(id,l,r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(u,v,val,id << 1,l,mid);
    upd(u,v,val,id << 1 | 1,mid + 1,r);
    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int get(int u,int v,int id = 1,int l = 1,int r = n) {
    down(id,l,r);
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) >> 1;
    return get(u,v,id << 1,l,mid) ^ get(u,v,id << 1 | 1,mid + 1,r);
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(i,i,a[i]);
    }

    while (q--) {
        int u,v,type;
        cin >> type;
        if (type == 1) {
            cin >> u >> v >> type;
            upd(u,v,type);
        } else {
            cin >> u;
            cout << get(u,u) << '\n';
        }
    }
    return 0;
}