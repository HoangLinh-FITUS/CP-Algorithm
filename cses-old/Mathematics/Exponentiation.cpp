#include <iostream>

using namespace std;
const int mod = 1e9 + 7;

int power(int a,int b) {
    if (b == 0) return 1;
    long long w = power(a,b >> 1);
    w *= w;
    w %= mod;
    if (b & 1) return w * a % mod;
    return w;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        cout << power(a,b) << '\n';
    }
    return 0;
}