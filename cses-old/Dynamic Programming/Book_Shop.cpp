#include <iostream>

using namespace std;
const int N = 1e3 + 1;

int h[N],s[N];
int n,x;
int dp[N * 100];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j],dp[j - h[i]] + s[i]);
        }
    }
    cout << dp[x];
    return 0;
}