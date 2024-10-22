#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[10000][10000],dem = 0;
long long h[] = {-1,1,0,0};
long long c[] = {0,0,1,-1};
void DFS(long long x,long long y)
{
    a[x][y] = 1;
    for (long long i = 0; i < 4; i++)
    {
        long long xx,yy;
        xx = x + h[i];
        yy = y + c[i];
        if (xx > 0 && yy > 0 && xx <= n && yy <= m && a[xx][yy] == 0)
        {
            dem++;
            DFS(xx,yy);
        }
    }
}
int main()
{
    freopen("RCSSNAIL1.INP","r",stdin);
    freopen("RCSSNAIL1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> x >> y;
    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= m; j++)
          cin >> a[i][j];
    DFS(x,y);
    cout << dem + 1;
}
