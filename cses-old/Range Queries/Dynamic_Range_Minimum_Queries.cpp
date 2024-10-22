#include <iostream>
#define int long long 

using namespace std;
const int N = 2e5 + 1;

int ST[4 * N];
int n,q;
int a[N];

void upd(int pos,int val,int id = 1,int l = 1,int r = n) {
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) upd(pos,val,id << 1,l,mid);
    else upd(pos,val,id << 1 | 1,mid + 1,r);
    ST[id] = min(ST[id << 1],ST[id << 1 | 1]);
}

int get(int u,int v,int id = 1,int l = 1,int r = n) {
    if (v < l || r < u) return 1e9;
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) >> 1;
    return min(get(u,v,id << 1,l,mid),get(u,v,id << 1 | 1,mid + 1,r));
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(i,a[i]);
    }
    while (q--) {
        int u,v,type;
        cin >> type >> u >> v;
        if (type == 1) upd(u,v);
        else cout << get(u,v) << '\n';
    }
    return 0;
}