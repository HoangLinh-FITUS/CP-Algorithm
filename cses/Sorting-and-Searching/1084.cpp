#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 1;

int n, m, k;
int a[N], b[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1,a + n + 1);
    sort(b + 1,b + m + 1);

    int res = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= m && b[j] < a[i] - k) j++;
        if (j <= m && b[j] <= a[i] + k) {
            res++;
            j++;
        }
    }    
    cout << res;
    return 0;
}