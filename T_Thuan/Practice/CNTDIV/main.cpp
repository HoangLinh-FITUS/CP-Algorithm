#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

int cnt[N];
int p[N];
int n;

void era()
{
    for (int i = 2; i <= N; i++) if (!p[i])
    {
        p[i] = i;
        for (int j = i * i; j <= N; j += i)
        {
            p[j] = i;
        }
    }
}

void break_down(int x, set <int> &s)
{
    while (x > 1)
    {
        int d = p[x];
        cnt[d]++;
        s.insert(d);
        x /= d;
    }
}

void solve()
{
    int n;
    cin >> n;
    set <int> s;
    break_down(n, s);
    break_down(n + 1, s);
    break_down(n + 2, s);
    int ans = 0;
    int res = 1;
    for (int x : s)
    {
        res *= (2 * cnt[x] + 1);
    }
    ans += (res - 1) / 2;
    res = 1;
    for (int x : s)
    {
        res *= cnt[x] + 1;
        cnt[x]= 0;
    }
    ans -= res - 1;
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    era();
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}
