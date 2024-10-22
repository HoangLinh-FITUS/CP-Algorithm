#include <bits/stdc++.h>
using namespace std;

bool inside_board(const int &x,const int &y) {
    return 1 <= x && x <= 10 && 1 <= y && y <= 10;
}

bool dd[11][11];
int check[11][11][11];

void Try(int x,int y,int n) {
    if (n == 0) {
        dd[x][y] = 1;
        return;
    }
    if (check[x][y][n]) return;
    check[x][y][n] = 1;
    if (inside_board(x + 1,y + 2)) Try(x + 1,y + 2,n - 1);
    if (inside_board(x + 1,y - 2)) Try(x + 1,y - 2,n - 1);
    if (inside_board(x + 2,y + 1)) Try(x + 2,y + 1,n - 1);
    if (inside_board(x + 2,y - 1)) Try(x + 2,y - 1,n - 1);
    if (inside_board(x - 1,y + 2)) Try(x - 1,y + 2,n - 1);
    if (inside_board(x - 1,y - 2)) Try(x - 1,y - 2,n - 1);
    if (inside_board(x - 2,y + 1)) Try(x - 2,y + 1,n - 1);
    if (inside_board(x - 2,y - 1)) Try(x - 2,y - 1,n - 1);
}

int main() {
    freopen("RCSKNIGH.INP","r",stdin);
    freopen("RCSKNIGH.OUT","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x,y,n;
        cin >> x >> y >> n;
        memset(dd,0,sizeof(dd));
        memset(check,0,sizeof(check));
        Try(x,y,n);
        int res = 0;
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) res += dd[i][j];
        }
        cout << res << '\n';
    }
}

