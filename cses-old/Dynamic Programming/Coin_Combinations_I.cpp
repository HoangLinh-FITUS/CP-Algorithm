#include <iostream>

using namespace std;

int n,x;
int a[101];
int dp[(int)1e6 + 1];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= n; j++) if (a[j] <= i) {
            dp[i] += dp[i - a[j]];
            dp[i] %= 1000000007;
        }
    }
    cout << dp[x];
    return 0;
}