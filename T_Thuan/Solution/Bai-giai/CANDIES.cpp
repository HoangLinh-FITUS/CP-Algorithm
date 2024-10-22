#include <bits/stdc++.h>

#define task "C"
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
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vl;
template <typename T> inline void read (T &x) {bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48; if (b)x=-x;}
template <typename T> inline void wrip(T x) {if (x > 9) wrip(x / 10); putchar(x%10 + 48); }
int T;
ll n, K, fib[74];
struct DP
{
    ll sum = 0, cnt[74];
    DP() {rep(i, 0, 73) cnt[i] = 0;}
};
DP f[75];
DP solve(ll N)
{
    int p = upper_bound(fib + 1, fib + 74, N) - fib - 1;
    if (fib[p] == N)
    {
        DP tmp = f[p];
        tmp.sum++;
        tmp.cnt[1]++;
        return tmp;
    }
    ll nn = N - fib[p];
    DP tmp = solve(nn), res;
    res.sum = f[p].sum + nn + 1 + tmp.sum;
    res.cnt[1] = f[p].cnt[1] + 1;
    rep(k, 2, 73) res.cnt[k] = f[p].cnt[k] + tmp.cnt[k - 1];
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
    fib[0] = fib[1] = 1;
    rep(i, 2, 73) fib[i] = fib[i - 1] + fib[i - 2];
    rep(i, 2, 73)
    {
        f[i].sum = f[i - 1].sum + fib[i - 2] + f[i - 2].sum;
        f[i].cnt[1] = f[i - 1].cnt[1] + 1;
        rep(k, 2, 73) f[i].cnt[k] = f[i - 1].cnt[k] + f[i - 2].cnt[k - 1];
    }
    read(T);
    while (T--)
    {
        read(n);
        read(K);
        DP res = solve(n);
        if (K > 73) puts("0");
        else
        {
            ll ans = res.sum;
            rep(i, 1, K - 1) ans -= res.cnt[i] * i;
            wrip(ans);
            putchar('\n');
        }
    }

    return 0;
}
