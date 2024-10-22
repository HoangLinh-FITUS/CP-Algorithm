#include <iostream>

using namespace std;
const int N = 2e5 + 1;

int n,q;
int up[N][20];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        up[i][0] = x;
    }

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) up[j][i] = up[up[j][i - 1]][i - 1];
    }

    while (q--) {
        int x,k;
        cin >> x >> k;
        for(int i = 19; i >= 0; i--) if ((1 << i) <= k) {
            k -= (1 << i);
            x = up[x][i];
        }
        if (!x) cout << -1; else cout << x;
        cout << '\n';
    }
    return 0;
}