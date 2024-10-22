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
const int N = 51;
int n, a[N];
bitset<N * N> can, g[N * N];
ii po[N], po1[N];

bool doIntersect(ii p1, ii q1, ii p2, ii q2)
{
    int A1 = (q1.y - p1.y), B1 = p1.x - q1.x, C1 = -A1 * p1.x - B1 * p1.y;
    int A2 = (q2.y - p2.y), B2 = p2.x - q2.x, C2 = -A2 * p2.x - B2 * p2.y;
    bool tmp = ((A1 * p2.x + B1 * p2.y + C1) * 1LL * (A1 * q2.x + B1 * q2.y + C1)) <= 0;
    bool tmp1 = ((A2 * p1.x + B2 * p1.y + C2) * 1LL * (A2 * q1.x + B2 * q1.y + C2)) <= 0;
    return (tmp && tmp1);
}
int ans = 0;
void Try(int num)
{
    if (num == n)
    {
        ans++;
        return;
    }
    bitset<N * N> tmp = can;
    rep(i, num * n, num * n + n - 1) if (can[i])
    {
        can &= g[i];
        Try(num + 1);
        can = tmp;
    }
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    rep(i, 0, n - 1) cin >> po1[i].x, po1[i].y = 0;
    rep(i, 0, n - 1) cin >> po[i].x >> po[i].y;
    rep(i, 0, n - 1)
    {
        rep(j, 0, n - 1)
        {
            g[i * n + j].set();
            rep(k, 0, n - 1) rep(t, 0, n - 1) if (doIntersect(po1[i], po[j], po1[k], po[t]))
            {
                g[i * n + j][k * n + t] = 0;
            }
        }
    }
    rep(i, 0, n * n - 1) can[i] = 1;
    Try(0);
    cout << ans;
    return 0;
}
