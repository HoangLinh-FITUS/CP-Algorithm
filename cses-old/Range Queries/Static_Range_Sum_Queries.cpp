#include <iostream>
#define int long long 

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,q;
    cin >> n >> q;
    int *a = new int[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while (q--) {
        int u,v;
        cin >> u >> v;
        cout << a[v] - a[u - 1] << '\n';
    }
    return 0;
}