#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    long long total_sum = 0;
    for(int i = 0; i < n; i++) cin >> a[i],total_sum += a[i];
    long long res = total_sum;
    for(int mask = 0; mask < (1 << n) - 1; mask++) {
        long long s = 0;
        for(int i = mask,j; i; i ^= (1 << j)) {
            j = __builtin_ctz(i);
            s += a[j];
        }
        res = min(res,abs(total_sum - 2 * s));
    }
    cout << res;
    return 0;
}