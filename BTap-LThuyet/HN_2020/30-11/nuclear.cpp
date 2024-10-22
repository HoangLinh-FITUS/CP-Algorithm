#include <bits/stdc++.h>

#define task "N"
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
int n, bit[N << 1], ans[N], q;
ii po[N], posx[N], r[2];
iii qu[N];
vi posy;
void upd(int p, int v)
{
    for (; p < N * 2 - 3; p += p & -p) bit[p] += v;
}
int query(int p)
{
    int res = 0;
    for (; p; p -= p & -p) res += bit[p];
    return res;
}
int dist(const ii &A, const ii &B)
{
    return (ceil((ld) sqrt((ld) (A.F - B.F) * (A.F - B.F) + (ld) (A.S - B.S) * (A.S - B.S))));
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
    rep(i, 1, n) cin >> po[i].F >> po[i].S;
    cin >> r[0].F >> r[0].S >> r[1].F >> r[1].S >> q;
    rep(i, 1, q) cin >> qu[i].F.F >> qu[i].F.S, qu[i].S = i;
    sort(qu + 1, qu + 1 + q);
    rep(i, 1, n)
    {
        int d1 = dist(r[0], po[i]);
        int d2 = dist(r[1], po[i]);
        posy.eb(d2);
        posx[i] = {d1, d2};
    }
    sort(all(posy));
    sort(posx + 1, posx + 1 + n);
    int ix = 1;
    rep(i, 1, q)
    {
        iii &Q = qu[i];
        while (ix <= n && posx[ix].F <= Q.F.F) upd(posx[ix].S, 1), ix++;
        int p = upper_bound(all(posy), Q.F.S) - posy.begin();
        ans[Q.S] = ix - 1 + p - query(Q.F.S);
    }
    rep(i, 1, q) cout << ans[i] << '\n';

    return 0;
}
