#include <iostream>
#define int long long 

using namespace std;
const int N = 2e5 + 10;
const int INF = 1e18;

int arr[N];
int n,a,b;
int ST[4 * N];

void upd(int id,int l,int r) {
    if (l == r) {
        ST[id] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1,l,mid);
    upd(id << 1 | 1,mid + 1,r);
    ST[id] = max(ST[id << 1],ST[id << 1 | 1]);
}

int get(int u,int v,int id = 1,int l = 1,int r = n) {
    if (v < l || r < u) return -INF;
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) >> 1;
    return max(get(u,v,id << 1,l,mid),get(u,v,id << 1 | 1,mid + 1,r));
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    upd(1,1,n);

    int res = -INF;
    for(int i = 1; i <= n - a + 1; i++) {
        int x = get(i + a - 1,min(i + b - 1,n));
        res = max(res,x - arr[i - 1]);
    }
    cout << res;
    return 0;
}