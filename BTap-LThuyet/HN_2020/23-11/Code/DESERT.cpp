#include <bits/stdc++.h>

#define task "DESERT"
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
typedef pair<int, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vl;
const int N = 1e5 + 2, INF = 2e9 + 1;
int n, posx[N];
ii bit[N];
struct Point
{
    int x, y, id;
} a[N];
void upd(int p, ii v)
{
    for (; p <= n; p += p & -p) if (bit[p].F < v.F) bit[p] = v;
}
int query(int p)
{
    int res = -INF, ans = 0;
    for (; p; p -= p & -p) if (res < bit[p].F) res = bit[p].F, ans = bit[p].S;
    return ans;
}
viii edge;
void solve(vector<Point> &po)
{
    vi com;
    for (Point &P : po) com.eb(P.x);
    sort(all(com));
    com.erase(unique(all(com)), com.end());
    for (Point &P : po) posx[P.id] = lower_bound(all(com), P.x) - com.begin() + 1;
    rep(i, 1, n) bit[i] = {-INF, 0};
    sort(all(po), [&](const Point &A, const Point &B)
    {
        return (A.y - A.x < B.y - B.x) || (A.y - A.x == B.y - B.x && A.x + A.y < B.x + B.y);
    });
    for (Point &P : po)
    {
        int u = query(posx[P.id]);
        if (u) edge.pb({{u, P.id}, 1ll * abs(a[P.id].x - a[u].x) + abs(a[P.id].y - a[u].y)});
        upd(posx[P.id], ii(P.x + P.y, P.id));
    }
}

int rt[N], rk[N], par[N];
int frt(int i) {return rt[i] == i ? i : rt[i] = frt(rt[i]);}
vii g[N];
ll ans = 0;
void dfs(int u, int p, ll mx)
{
    par[u] = p;
    if (u == n) ans = mx;
    for (ii v : g[u]) if (v.F != p) dfs(v.F, u, max(mx, v.S));
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    vector<Point> po;
    rep(i, 1, n) po.pb(a[i]);
    solve(po);
    rep(i, 1, n) po[i - 1] = {a[i].x - a[i].y, a[i].x + a[i].y, a[i].id};
    solve(po);
    rep(i, 1, n) po[i - 1] = {-a[i].y, a[i].x, a[i].id};
    solve(po);
    rep(i, 1, n) po[i - 1] = {-a[i].x - a[i].y, a[i].x - a[i].y, a[i].id};
    solve(po);
    rep(i, 1, n) po[i - 1] = {-a[i].x, -a[i].y, a[i].id};
    solve(po);
    rep(i, 1, n) po[i - 1] = {-a[i].x + a[i].y, -a[i].x - a[i].y, a[i].id};
    solve(po);
    rep(i, 1, n) po[i - 1] = {a[i].y, -a[i].x, a[i].id};
    solve(po);
    rep(i, 1, n) po[i - 1] = {a[i].x + a[i].y, -a[i].x + a[i].y, a[i].id};
    solve(po);
    sort(all(edge), [&](const iii &A, const iii &B)
    {
        return A.S < B.S;
    });

    int cnt = 0;
    rep(i, 1, n) rt[i] = i;
    for (iii &E : edge)
    {
        int x = frt(E.F.F), y = frt(E.F.S);
        if (x != y)
        {
            if (rk[x] == rk[y]) rk[x]++;
            if (rk[x] < rk[y]) swap(x, y);
            rt[y] = x;
            g[E.F.F].eb(E.F.S, E.S);
            g[E.F.S].eb(E.F.F, E.S);
            if (++cnt == n - 1) break;
        }
    }
    dfs(1, 0, 0);
    vi res;
    cout << ans << '\n';
    for (int u = n; u; u = par[u]) res.eb(u);
    Rep(i, SZ(res) - 1, 0) cout << res[i] << ' ';
    return 0;
}
