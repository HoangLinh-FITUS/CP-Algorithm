#include <bits/stdc++.h>

#define task "R"
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
const int N = 2e5 + 2;
int n, M, a[N], dp[N], bit[N];
ll s[N];
vl com;
void upd(int p, int v)
{
    for (; p; p -= p & -p) bit[p] = max(bit[p], v);
}
int query(int p)
{
    int res = -1e9;
    for (; p <= SZ(com); p += p & -p) res = max(res, bit[p]);
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
    cin >> n >> M;
    rep(i, 1, n) cin >> a[i];
    Rep(i, n, 0) s[i] = s[i + 1] + M;
    rep(i, 0, n + 1) com.eb(a[i] + s[i]);
    sort(all(com));
    com.erase(unique(all(com)), com.end());
    fill(bit, bit + 1 + SZ(com), -1e9);
    int p = lower_bound(all(com), s[0]) - com.begin() + 1;
    upd(p, 0);
    rep(i, 1, n + 1)
    {
        int p = lower_bound(all(com), a[i] + s[i]) - com.begin() + 1;
        dp[i] = query(p) + 1;
        if (dp[i] > 0) upd(p, dp[i]);
    }
    cout << n + 1 - dp[n + 1];
    return 0;
}
