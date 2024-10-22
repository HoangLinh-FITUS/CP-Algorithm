#include <iostream>

using namespace std;

int n,a[101],x;
int dp[2][(int)1e6 + 1];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = dp[1][0] = 1;
    int now = 1,last = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            dp[now][j] = dp[last][j];
            if (a[i] <= j) dp[now][j] += dp[now][j - a[i]];
            dp[now][j] %= (int)1e9 + 7;
        }
        swap(now,last);
    }
    cout << dp[last][x];
    return 0;
}