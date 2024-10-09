#include <iostream>
#include <bitset>

using namespace std;

int n;
int a[21];
long long total = 0, s1 = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], total += a[i];
    
    long long res = total;
    for (int i = 0; i < (1 << n); i++) {
        s1 = 0;
        for (int tmp = i, j; tmp; tmp ^= (1 << j)) {
            j = __builtin_ctz(tmp);
            s1 += a[j];
        }
        res = min(res, abs(total - 2 * s1));
    }
    cout << res;
    return 0;
}