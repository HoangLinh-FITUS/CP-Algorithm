#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,x;
    cin >> n >> x;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a + n);
    int res = 0,j = 0;
    for(int i = n - 1; i >= j; i--) {
        if (a[i] + a[j] <= x) j++;
        res++;
    }
    cout << res;
    return 0;
}