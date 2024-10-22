#include <bits/stdc++.h>

using namespace std;

#define el '\n'

int n;
string a[111];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a+n, greater<string>());
  for (int i = 0; i < n; ++i) cout << a[i];
  return 0;
}
