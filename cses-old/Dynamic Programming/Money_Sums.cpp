#include <iostream>

using namespace std;

int n,a[101],x;
int dp[2][(int)1e5 + 1];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    int S = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = dp[1][0] = 1;
    int now = 1,last = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= S; j++) {
            dp[now][j] = dp[last][j];
            if (a[i] <= j) dp[now][j] += dp[last][j - a[i]];
        }
        swap(now,last);
    }
    int cnt = 0;
    for(int i = 1; i <= S; i++) if (dp[last][i]) cnt++;
    cout << cnt << '\n';
    for(int i = 1; i <= S; i++) if (dp[last][i]) cout << i << " ";
    return 0;
}