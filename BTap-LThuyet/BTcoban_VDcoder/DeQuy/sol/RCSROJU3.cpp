#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<long long,long long> ii;
char a[1000][1000];
queue <ii> q;
long long n,m,xc,yc,xd,yd;
ii trace[1000][1000];
long long h[] = {-1,1,0,0};
long long c[] = {0,0,1,-1};
vector <ii> b;

void BFS()
{
    a[xd][yd] = 'x';
    q.push(ii(xd,yd));
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (long long i = 0; i < 4; i++)
        {
            long long x,y;
            x = u.fi + h[i];
            y = u.se + c[i];
            if (x > 0 && y > 0 && x <= n && y <= m && a[x][y] == 'o')
            {
                trace[x][y] = ii(u.fi,u.se);
                a[x][y] = 'x';
                q.push(ii(x,y));
            }
        }
    }
}
int main()
{
    freopen("RCSROJU3.INP","r",stdin);
    freopen("RCSROJU3.OUT","w",stdout);
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
    BFS();
    if (a[xc][yc] == 'x')
        cout << "YES" << endl;
    else
        {
            cout << "NO" << endl;
            exit(0);
        }
    long long i = xc,j = yc;
    while (ii(i,j) != ii(0,0))
    {
        b.push_back(ii(i,j));
        ii tv = trace[i][j];
        i = tv.fi;
        j = tv.se;
    }
    cout << b.size() << endl;
    for (long long i = b.size()-1; i >= 0; i--)
        cout << b[i].fi << " " << b[i].se << endl;
    return 0;
}
