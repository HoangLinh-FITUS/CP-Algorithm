#include <iostream>
#define int long long 

using namespace std;

int a[5001];
int n;
int me[5001][5001][2];

int calc(int i,int j,bool player) {
    if (i > j) return 0;
    if (me[i][j][player] != -1e18) return me[i][j][player];
    if (!player) return me[i][j][player] = max(calc(i + 1,j,1) + a[i],calc(i,j - 1,1) + a[j]);
    return me[i][j][player] = min(calc(i + 1,j,0),calc(i,j - 1,0));
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            me[i][j][0] = me[i][j][1] = -1e18;
        }
    }
    cout << calc(1,n,0) << '\n';

    return 0;
}