#include <bits/stdc++.h>

#define task "T"
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (int i = (r); i >= (l); --i)
#define DB(X) { cerr << #X << " = " << (X) << '\n'; }
#define DB1(A, _) { cerr << #A << "[" << _ << "] = " << (A[_]) << '\n'; }
#define DB2(A, _, __) { cerr << #A << "[" << _ << "][" << __ << "] = " << (A[_][__]) << '\n'; }
#define DB3(A, _, __, ___) { cerr << #A << "[" << _ << "][" << __ << "][" << ___ << "] = " << (A[_][__][___]) << '\n'; }
#define PR(A, l, r) { cerr << '\n'; rep(_, l, r) DB1(A, _); cerr << '\n';}
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define pf push_front
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define next ___next
#define prev ___prev
#define y1 ___y1
#define left ___left
#define right ___right
#define y0 ___y0
#define div ___div
#define j0 ___j0
#define jn ___jn

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
const int N = 12;
int n, pw3[N], mem[177148][21], a[N << 1][N << 1];
ii track[177148][21];
int getBit(int mask, int i)
{
    return (mask / pw3[i]) % 3;
}
int dp(int mask, int cur)
{
    if (mask == pw3[n + 1] - 1) return a[cur][0];
    int &res = mem[mask][cur];
    if (res != -1) return res;
    res = 1e9;
    rep(i, 0, 2 * n)
    {
        int nm = mask;
        if (i > n && getBit(mask, i - n) == 1) nm += pw3[i - n];
        if (i <= n && getBit(mask, i) == 0) nm += pw3[i];
        if (res > a[cur][i] + dp(nm, i))
        {
            res = a[cur][i] + dp(nm, i);
            track[mask][cur] = {nm, i};
        }
    }
    return res;
}
int main()
{
#ifdef HynDuf
    freopen(task".in", "r", stdin);
    //freopen(task".out", "w", stdout);
#else
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif
    cin >> n;
    rep(i, 0, 2 * n) rep(j, 0, 2 * n) cin >> a[i][j];
    pw3[0] = 1;
    rep(i, 1, n + 1) pw3[i] = pw3[i - 1] * 3;
    memset(mem, -1, sizeof(mem));
    cout << dp(2, 0) << '\n';
    int mask = 2, cur = 0;
    vi res;
    res.eb(0);
    while (1)
    {
        if (mask == pw3[n + 1] - 1) break;
        ii tr = track[mask][cur];
        cur = tr.S;
        mask = tr.F;
        res.eb(cur);
    }
    cout << SZ(res) + 1 << '\n';
    for (int v : res) cout << v << ' ';
    cout << 0;
    return 0;
}
