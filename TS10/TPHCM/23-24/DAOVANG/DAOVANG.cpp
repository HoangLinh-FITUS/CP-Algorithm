#include <iostream>
#include <algorithm>

using namespace std;

bool check(int *X,int n,int k,int R) {
    int T = X[0];
    for(int i = 1; i < n; i++) {
        if (X[i] > T + 2ll * R) {
            T = X[i];
            k--;
        }
    }
    return k >= 1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin >> n >> k;
    int *X = new int[n];
    for(int i = 0; i < n; i++) cin >> X[i];
    sort(X,X + n);
    int res = 0;
    for(int L = 1,R = 1e9; L <= R; ) {
        int mid = (L + R) >> 1;
        if (check(X, n, k, mid)) res = mid,R = mid - 1;
        else L = mid + 1;
    }
    cout << res;
    return 0;
}