#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> m >> n;
    int *p = new int[m];
    for(int i = 0; i < m; i++) cin >> p[i];
    sort(p,p + m,greater<int>());
    int res = p[0];
    for(int i = 1; i < min(m,n); i++) res = max(res,p[i] * (i + 1));
    cout << res;
    return 0;
}