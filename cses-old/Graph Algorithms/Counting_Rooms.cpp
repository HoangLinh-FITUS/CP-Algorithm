#include <iostream>

using namespace std;
const int N = 1e3 + 1;

int n,m;
char a[N][N];

bool inside(int x,int y) {
    return 0 < x && x <= n && 0 < y && y <= m && a[x][y] == '.';
}

void dfs(int i,int j) {
    a[i][j] = '#';
    if (inside(i + 1,j)) dfs(i + 1,j);
    if (inside(i - 1,j)) dfs(i - 1,j);
    if (inside(i,j - 1)) dfs(i,j - 1);
    if (inside(i,j + 1)) dfs(i,j + 1); 
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if (a[i][j] == '.') {
            res++;
            dfs(i,j);
        }
    }
    cout << res;
    return 0;
}