#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    for(int i = 1; i <= n; i++) dp[i] = 1e9;
    int res = 1;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        int x = lower_bound(dp + 1,dp + n + 1,val) - dp;
        res = max(res,x);
        dp[x] = val;
    }
    cout << res;
    return 0;
}