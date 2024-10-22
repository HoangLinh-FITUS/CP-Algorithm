#include <bits/stdc++.h>

using namespace std;

int n, a[105], ans = 0;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		while(a[i] != 0) {
			int tmp = a[i];
			for(int j = i + 1; j <= n; j++) {
				if(a[j] == 0) break;
				tmp = min(tmp, a[j]);
			}
			ans += tmp;
			for(int j = i; j <= n; j++) {
				if(a[j] == 0) break;
				a[j] -= tmp;
			}
		}
	}
	cout << ans;
}
