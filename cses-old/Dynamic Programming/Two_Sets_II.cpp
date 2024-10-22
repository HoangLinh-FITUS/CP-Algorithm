#include <iostream>

using namespace std;
#define mod 1000000007

int n,x;
int dp[500005];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    if (n % 4 != 0 && (n + 1) % 4 != 0) return cout << 0,0;
    int S = n * (n + 1) / 2;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = S >> 1; j >= i; j--) {
            dp[j] += dp[j - i];
            dp[j] %= mod;
        }
    }
    cout << 1ll * dp[S >> 1] * 500000004 % mod;
    return 0;
}