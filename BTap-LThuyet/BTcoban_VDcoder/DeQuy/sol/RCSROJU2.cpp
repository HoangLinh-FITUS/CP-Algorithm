#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> ii;
long long n,m,xd,xc,yd,yc;
char a[1000][1000];
long long h[] = {-1,1,0,0};
long long c[] = {0,0,1,-1};
string ok = "NO";
ii trace[1000][1000];
vector <ii> b;
void DFS(long long u,long long v)
{
    a[u][v] = 'x';
    for (long long i = 0; i < 4; i++)
    {
        long long x,y;
        x = u + h[i];
        y = v + c[i];
        if (x > 0 && y > 0 && x <= n && y <= m && a[x][y] == 'o')
        {
            if (x == xc && y == yc)
                ok = "YES";
            trace[x][y] = ii(u,v);
            DFS(x,y);
        }
    }
}
int main()
{
    freopen("RCSROJU2.INP","r",stdin);
    freopen("RCSROJU2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= m; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == 'R')
        {
            xd = i;
            yd = j;
        }
        if (a[i][j] == 'J')
        {
            xc = i;
            yc = j;
        }
    }
    a[xc][yc] = 'o';
    DFS(xd,yd);
    if (a[xc][yc] == 'x')
        cout << ok << endl;
    else
        {
            cout << ok << endl;
            exit(0);
        }
    long long i = xc,j = yc;
    while (ii(i,j) != ii(0,0))
    {
        b.push_back(ii(i,j));
        ii tv = trace[i][j];
        i = tv.first;
        j = tv.second;
    }
    cout << b.size() << endl;
    for (long long i = b.size()-1; i >= 0; i--)
        cout << b[i].first << " " << b[i].second << endl;
    return 0;
}
