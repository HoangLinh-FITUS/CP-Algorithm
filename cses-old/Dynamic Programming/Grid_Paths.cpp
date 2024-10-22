#include <iostream>

using namespace std;
const int N = 1e3 + 1;

int n;
char a[N][N];
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }

    dp[1][1] = (a[1][1] == '.');
    a[1][1] = '*';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) if (a[i][j] != '*') {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }
    cout << dp[n][n];
    return 0;
}