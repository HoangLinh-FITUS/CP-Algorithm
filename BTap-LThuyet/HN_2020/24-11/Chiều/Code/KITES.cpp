#include <bits/stdc++.h>

#define task "KITES"
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
#define x first
#define y second
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
const int N = 52, mod = 1e9 + 7, INF = 1e4 + 1;
int n, mem[N][N][N][N];
ii po[N], po1[N];

bool doIntersect(ii p1, ii q1, ii p2, ii q2)
{
    int A1 = (q1.y - p1.y), B1 = p1.x - q1.x, C1 = -A1 * p1.x - B1 * p1.y;
    int A2 = (q2.y - p2.y), B2 = p2.x - q2.x, C2 = -A2 * p2.x - B2 * p2.y;
    bool tmp = ((A1 * p2.x + B1 * p2.y + C1) * 1LL * (A1 * q2.x + B1 * q2.y + C1)) <= 0;
    bool tmp1 = ((A2 * p1.x + B2 * p1.y + C2) * 1LL * (A2 * q1.x + B2 * q1.y + C2)) <= 0;
    return (tmp && tmp1);
}
int dp(int l, int r, int i, int j)
{
    if (l > r) return 0;
    int &res = mem[l][r][i][j];
    if (res != -1) return res;
    res = 0;
    int num = 0, mx = -1, mxi = 0, mn = min(po[i].y, po[j].y);
    rep(k, 1, n) if (po[k].y <= mn && !doIntersect(po1[l], po[i], po1[r], po[k]) && !doIntersect(po1[r], po[j], po1[l], po[k]))
    {
        num++;
        //DB(k);
        if (mx < po[k].y) mx = po[k].y, mxi = k;
    }
    //DB(num);
    if (num != r - l - 1) return res = 0;
    if (num == 0) return res = 1;
    rep(k, l + 1, r - 1) (res += dp(l, k, i, mxi) * 1LL * dp(k, r, mxi, j) % mod) %= mod;
    return res;
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    rep(i, 1, n) cin >> po1[i].x, po1[i].y = 0;
    rep(i, 1, n) cin >> po[i].x >> po[i].y;
    sort(po1 + 1, po1 + 1 + n);
    po1[0] = {-1, 0}, po1[n + 1] = {INF, 0};
    sort(po + 1, po + n + 1);
    po[0] = {-1, INF}, po[n + 1] = {INF, INF};
    memset(mem, -1, sizeof(mem));
    //DB(dp(2, 3, 2, 3));
    cout << dp(0, n + 1, 0, n + 1);
    return 0;
}
