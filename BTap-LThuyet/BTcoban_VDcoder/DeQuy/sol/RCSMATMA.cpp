#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[21][21];
bool dd[21][21];

bool inside(const int &x,const int &y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int h[] = {0,0,-1,1};
int c[] = {1,-1,0,0};

int dfs(int u,int v) {
    dd[u][v] = 1;
    int res = 0;
    for(int i = 0; i < 4; i++) {
        int x = h[i] + u;
        int y = c[i] + v;
        if (inside(x,y) && !dd[x][y] && a[u][v] <= a[x][y]) {
            res = max(res,dfs(x,y) + 1);
        }
    }
    dd[u][v] = 0;
    return res;
}

int main() {
	freopen("RCSMATMA.INP","r",stdin);
	freopen("RCSMATMA.OUT","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            a[i][j] = x - 'A';
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) res = max(res,dfs(i,j) + 1);
    }
    cout << res;
}
    