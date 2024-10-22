#include <iostream>

using namespace std;
const int N = 1e3 + 1;

int a[N][N];
int n, q;

int get(int x1,int y1,int x2,int y2) {
    return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if (x == '*') a[i][j] = 1;
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    while (q--) {
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        cout << get(x,y,u,v) << '\n';
    }
    return 0;
}