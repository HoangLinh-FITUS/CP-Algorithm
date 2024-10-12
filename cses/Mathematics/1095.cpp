#include <iostream>

using namespace std;
const int mod = 1e9 + 7;

int power(int a, int b) {
    if (b == 0) return 1;
    int w = power(a, b >> 1);
    w = 1ll * w * w % mod;
    if (b & 1) return 1ll * w * a % mod;
    return w;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << power(a, b) << '\n';
    }
    return 0;
}