#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int a,b,c;
    cin >> a >> b >> c;
    int flr_a = a / c;
    int flr_b = b / c;
    if (flr_a == flr_b)
    {
        cout << (b - a) / 2 + (b - a) % 2;
        return 0;
    }
    int ans = 0;
    int tmp = (a / c + 1) * c + 1;
    ans += (tmp - a) / 2 + (tmp - a) % 2;
    a = tmp;
    flr_a++;
    ans += (flr_b - flr_a) * (c / 2 + c % 2);
    a = flr_b * c + 1;
    ans += (b - a) / 2 + (b - a) % 2;
    cout << ans;
    return 0;
}
