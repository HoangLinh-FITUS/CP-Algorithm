#include <iostream>

using namespace std;
const int N = 1e6 + 1;

int dp[N];
int n;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(i,6); j++) (dp[i] += dp[i - j]) %= 1000000007;
    }
    cout << dp[n];
    return 0;
}