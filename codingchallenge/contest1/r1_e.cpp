#include <iostream>
#include <math.h>

using namespace std;
const int N = 1e5 + 1, mod = 1e9 + 7;

int a[N];
int n;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int LCM(int a,int b) {
    return a / gcd(a,b) * b;
}

int ST[N * 4];

void update(int id, int l, int r) {
    if (l == r) {
        ST[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);
    ST[id] = LCM(ST[id << 1], ST[id << 1 | 1]);
}

int get(int u, int v, int id, int l, int r) {
    if (v < l || r < u) return 1;
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) >> 1;
    return LCM(get(u, v, id << 1, l, mid), get(u, v, id << 1 | 1, mid + 1, r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    update(1, 1, n);
    int res = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            res = 1ll * res * get(i, j, 1, 1, n) % mod;
        }
    }
    cout << res;
    return 0;
}