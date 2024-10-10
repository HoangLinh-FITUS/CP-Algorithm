#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 1;

int n, x;
int a[N];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int l = 1, r = n, res = 0;
    while (l <= r) {
        if (a[l] + a[r] <= x) l++;
        r--;
        res++;
    }

    cout << res;
    return 0;
}