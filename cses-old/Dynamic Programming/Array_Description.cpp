#include <iostream>

using namespace std;
const int N = 1e5 + 1;
const int mod = 1e9 + 7;

int n,m;
int a[N];
int dp[N][101];

void add(int &x,int &y) {
    x += y;
    if (x > mod) x -= mod;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        if (a[1]) return cout << 1,0;
        else return cout << m,0;
    }
    
    for(int j = 1; j <= m; j++) {
        if (a[1] == 0) {
            for(int k = 1; k <= m; k++) if (abs(j - k) <= 1) dp[1][j]++;
        }
        else if (abs(a[1] - j) <= 1) dp[1][j] = 1;
    }
    
    for(int i = 2; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            if (a[i] == 0) {
                add(dp[i][j],dp[i - 1][j]);
                if (j + 1 <= m) add(dp[i][j],dp[i - 1][j + 1]);
                if (j - 1 >= 1) add(dp[i][j],dp[i - 1][j - 1]);
            }
            else if (abs(j - a[i]) <= 1) add(dp[i][j],dp[i - 1][a[i]]);
        }
    }
    int res = 0;
    if (a[n]) res = dp[n - 1][a[n]];
    else for(int i = 1; i <= m; i++) add(res,dp[n - 1][i]);
    cout << res;
    return 0;
}