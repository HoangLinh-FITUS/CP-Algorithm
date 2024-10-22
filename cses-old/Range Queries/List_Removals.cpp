#include <iostream>

using namespace std;
const int N = 2e5 + 1;

int a[N];
int n;
int ST[N << 2],lazy[N << 2];

void down(int id,int l,int r) {
    if (lazy[id]) {
        ST[id] += lazy[id];
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
    ST[id] = max(ST[id << 1],ST[id << 1 | 1]);
}

int get(int k,int id = 1,int l = 1,int r = n) {
    down(id,l,r);
    if (l == r) {
        upd(l,l,-l);
        upd(l,n,-1);
        return l;
    }
    int mid = (l + r) >> 1;
    down(id << 1,l,mid);
    if (ST[id << 1] >= k) return get(k,id << 1,l,mid);
    return get(k,id << 1 | 1,mid + 1,r);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) upd(i,i,i);

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        cout << a[get(k)] << " ";
    }
    return 0;
}