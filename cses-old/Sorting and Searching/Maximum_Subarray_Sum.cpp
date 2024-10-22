#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    long long s = 0,res = -1e18;
    for(int i = 0; i < n; i++) {
        s = max(1ll * a[i],s + a[i]);
        res = max(res,s);
    }
    cout << res;
    return 0;
}