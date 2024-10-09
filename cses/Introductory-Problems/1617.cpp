#include <iostream>

using namespace std;
const int mod = 1e9 + 7;

int power(int x, int y) {
    if (y == 0) return 1;
    int w = power(x, y >> 1);
    if (y & 1) return 1ll * w * w % mod * x % mod;
    return 1ll * w * w % mod; 
}

int main() {
    int n;
    cin >> n;
    cout << power(2, n) << '\n';
}