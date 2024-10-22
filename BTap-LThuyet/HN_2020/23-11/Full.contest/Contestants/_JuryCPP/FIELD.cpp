#define taskname "FIELD"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxMN = 1000;
int m, n;
int a[maxMN][maxMN];

void ReadInput()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
}

void Solve()
{
    int res = 0;
    for (int x = 0; x < m; ++x)
    {
        int y1 = x * n / m; //floor(x * n / m)
        int y2 = ((x + 1) * n + m - 1) / m; //ceil((x + 1) * n / m)
        for (int y = y1; y < y2; ++y)
            res += a[x][y];
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Solve();
}
