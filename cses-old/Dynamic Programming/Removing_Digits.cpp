#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = 1e9;
        int x = i;
        while (x) {
            dp[i] = min(dp[i],dp[i - x % 10] + 1);
            x /= 10;
        }
    }
    cout << dp[n];
    return 0;
}