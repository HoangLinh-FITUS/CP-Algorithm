#include <iostream>

using namespace std;
const int N = 501;

int p[N], w[N];
int dp[N][10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int E, F,n;
		cin >> E >> F;
		int S = F - E;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> p[i] >> w[i];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= S; j++) dp[i][j] = 1e9;
		}
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= S; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j >= w[i]) dp[i][j] = min(dp[i][j], dp[i][j - w[i]] + p[i]);
			}
		}
		if (dp[n][S] == (int)1e9) cout << "-1\n"; else 
		cout << dp[n][S] << '\n';
	}
	return 0;
}