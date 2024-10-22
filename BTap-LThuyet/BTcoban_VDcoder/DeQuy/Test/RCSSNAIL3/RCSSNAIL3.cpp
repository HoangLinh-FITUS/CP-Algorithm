#include <bits/stdc++.h>
using namespace std;
long long n,m,xd,yd,a[1000][1000],dem = 0,MAX = 0;
long long h[] = {-1,1,0,0};
long long c[] = {0,0,1,-1};
vector <long long> b;
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
    freopen("RCSSNAIL3.INP","r",stdin);
    freopen("RCSSNAIL3.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= m; j++)
            cin >> a[i][j];
    for (long long l = 1; l <= n; l++)
        for (long long ll = 1; ll <= m; ll++)
            if (a[l][ll] == 0)
            {
                dem = 1;
                DFS(l,ll);
                b.push_back(dem);
            }
    cout << b.size() << endl;
    sort(b.begin(),b.end());
    for (long long i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    return 0;
}
