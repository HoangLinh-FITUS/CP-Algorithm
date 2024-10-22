#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int m,n,k;
    cin >> m >> n >> k;
    int *a = new int[m];
    int *b = new int[n];
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a,a + m);
    sort(b,b + n);
    int res = 0;
    for(int i = 0,j = 0; i < m; i++) {
        while (j < n && b[j] < a[i] - k) j++;
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) res++,j++;
    }
    cout << res;
    return 0;
}