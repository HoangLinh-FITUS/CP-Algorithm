#pragma comment(linker, "/STACK:268435456");
#include <bits/stdc++.h>
using namespace std;

bool dd[1001][1001];
bool check[1001][1001];
int n,u1,v1,u2,v2,sx,sy,x,y;

bool inside(const int &u,const int &v) {
    return 1 <= u && u <= n && 1 <= v && v <= n && !dd[u][v] && !check[u][v];
}

void Find(int u,int v) {
    check[u][v] = 1;
    if (inside(u - 1,v)) Find(u - 1,v);
    if (inside(u - 1,v - 1)) Find(u - 1,v - 1);
    if (inside(u - 1,v + 1)) Find(u - 1,v + 1);
    if (inside(u,v + 1)) Find(u,v + 1);
    if (inside(u,v - 1)) Find(u,v - 1);
    if (inside(u + 1,v)) Find(u + 1,v);
    if (inside(u + 1,v - 1)) Find(u + 1,v - 1);
    if (inside(u + 1,v + 1)) Find(u + 1,v + 1);
}

int main() {
    freopen("RCSKING.INP","r",stdin);
    freopen("RCSKING.OUT","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> u1 >> v1 >> u2 >> v2 >> sx >> sy >> x >> y;
    // (u1,v1) (u2,v2) : la vi tri quan hay
    // (sx,sy) : la vi tri Start
    // (x,y) : la vi tri End
    for(int i = 1; i <= n; i++) dd[i][v1] = dd[i][v2] = 1;
    for(int j = 1; j <= n; j++) dd[u1][j] = dd[u2][j] = 1;
    for(int i = u1,j = v1; i > 0 && j > 0; i--,j--) dd[i][j] = 1;
    for(int i = u2,j = v2; i > 0 && j > 0; i--,j--) dd[i][j] = 1;
    for(int i = u1,j = v1; i > 0 && j <= n; i--,j++) dd[i][j] = 1;
    for(int i = u2,j = v2; i > 0 && j <= n; i--,j++) dd[i][j] = 1;
    for(int i = u1,j = v1; i <= n && j > 0; i++,j--) dd[i][j] = 1;
    for(int i = u2,j = v2; i <= n && j > 0; i++,j--) dd[i][j] = 1;
    for(int i = u1,j = v1; i <= n && j <= n; i++,j++) dd[i][j] = 1;
    for(int i = u2,j = v2; i <= n && j <= n; i++,j++) dd[i][j] = 1;
    Find(sx,sy);
    if (check[x][y]) cout << "YES"; else cout << "NO";
}
