#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;


int n,m,t,k;
int a[2][N];
int ans[2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> m >> t >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[0][i];
        a[0][i] = min(a[0][i], t);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[1][i];
        a[1][i] = min(a[1][i], t);
    }
    a[0][n + 1] = t;
    a[1][m + 1] = t;
    bool ok_to_switch = true;
    for (int cur = 0, i[2] = {0, 0}, pos = 0; cur < t;)
    {
        while (a[pos][i[pos] + 1] <= cur) i[pos]++;
        if (i[pos] && (a[pos][i[pos]] + k > cur))
        {
            if (ok_to_switch)
            {
                ok_to_switch = false;
                pos ^= 1;
            } else {
                cur = a[pos][i[pos]] + k;
                ok_to_switch = true;
            }
        } else {
            ans[pos] += a[pos][i[pos] + 1] - cur;
            cur = a[pos][i[pos] + 1];
            ok_to_switch = true;
        }
    }
    cout << ans[0] << " " << ans[1];
    return 0;
}
