#include <iostream>

using namespace std;

long long cnt_divisors(int n) {
    long long res = 1;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        res *= (cnt + 1);
    }
    if (n > 1) res *= 2;
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << cnt_divisors(n) << '\n';
    }
    return 0;
}