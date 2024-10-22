#include <iostream>

using namespace std;
#define int long long 

int power(int a,int b,int mod) {
    if (b == 0) return 1;
    int w = power(a,b >> 1,mod);
    w *= w;
    w %= mod;
    if (b & 1) return w * a % mod;
    return w;
}

const int mod = 1e9 + 7;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin >> a >> b >> c;
        cout << power(a,power(b,c,mod - 1),mod) << '\n';
    }
    return 0;
}