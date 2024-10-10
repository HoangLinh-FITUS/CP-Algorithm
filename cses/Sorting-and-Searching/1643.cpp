#include <iostream>

using namespace std;
const int N = 2e5 + 1;

int n;
long long a[N];

int main() {
    // sum[R] - Sum[L - 1] = MAX -> Sum[L - 1] = min 

    cin >> n;   
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];

    long long Min = 0, res = -1e18;
    for (int i = 1; i <= n; i++) {
        res = max(res, a[i] - Min);
        Min = min(Min, a[i]);
    }
    cout << res;

    return 0;
}