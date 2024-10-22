#include <bits/stdc++.h>

#define task "SQUARE"
#define aint(v) (v).begin(), (v).end()
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
using uint = unsigned long long;
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<int> vl;
template <typename T> inline void read (T &x) {bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48; if (b)x=-x;}
template <typename T> inline void wrip(T x) {if (x > 9) wrip(x / 10); putchar(x%10 + 48); }
const int INF = 1e9;
int T, n;
struct HV
{
    int mnx, mny, mxx, mxy;
} suf[100002];
vii po;
bool check(int x, int y, int x1, int y1)
{
    assert(x <= x1);
    assert(y <= y1);
    int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
    for (ii P : po) if (!(P.F >= x && P.F <= x1 && P.S >= y && P.S <= y1))
    {
        mnx = min(mnx, P.F);
        mny = min(mny, P.S);
        mxx = max(mxx, P.F);
        mxy = max(mxy, P.S);
        if (max(mxy - mny, mxx - mnx) > x1 - x) return 0;
    }
    return 1;
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    read(T);
    while (T--)
    {
        po.clear();
        read(n);
        int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
        rep(i, 1, n)
        {
            int x, y;
            read(x);
            read(y);
            po.eb(x, y);
            mnx = min(mnx, x);
            mny = min(mny, y);
            mxx = max(mxx, x);
            mxy = max(mxy, y);
        }
        int ans = 0;
        int l = 1, r = max(mxx - mnx, mxy - mny);
        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (check(mnx, mny, mnx + m, mny + m)) r = m - 1;
            else l = m + 1;
        }
        ans = l;
        l = 1, r = max(mxx - mnx, mxy - mny);
        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (check(mnx, mxy - m, mnx + m, mxy)) r = m - 1;
            else l = m + 1;
        }
        ans = min(ans, l);

        wrip(ans);
        putchar(' ');

        ans = 2e9;
        suf[n] = {INF, INF, -INF, -INF};
        sort(aint(po));

        Rep(i, n - 1, 0)
        {
            suf[i].mnx = min(suf[i + 1].mnx, po[i].F);
            suf[i].mny = min(suf[i + 1].mny, po[i].S);
            suf[i].mxx = max(suf[i + 1].mxx, po[i].F);
            suf[i].mxy = max(suf[i + 1].mxy, po[i].S);
        }
        mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
        for (int i = 0, j = 0; i < n; i = j)
        {
            while (j < n && po[j].F == po[i].F) j++;
            rep(k, i, j - 1)
            {
                mnx = min(mnx, po[k].F);
                mny = min(mny, po[k].S);
                mxx = max(mxx, po[k].F);
                mxy = max(mxy, po[k].S);
            }
            ans = min(ans, max({mxx - mnx, mxy - mny, suf[j].mxx - suf[j].mnx, suf[j].mxy - suf[j].mny}));
        }

        suf[n] = {INF, INF, -INF, -INF};
        sort(aint(po), [&](const ii &A, const ii &B)
        {
            return A.S < B.S;
        });
        Rep(i, n - 1, 0)
        {
            suf[i].mnx = min(suf[i + 1].mnx, po[i].F);
            suf[i].mny = min(suf[i + 1].mny, po[i].S);
            suf[i].mxx = max(suf[i + 1].mxx, po[i].F);
            suf[i].mxy = max(suf[i + 1].mxy, po[i].S);
        }
        mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
        for (int i = 0, j = 0; i < n; i = j)
        {
            while (j < n && po[j].S == po[i].S) j++;
            rep(k, i, j - 1)
            {
                mnx = min(mnx, po[k].F);
                mny = min(mny, po[k].S);
                mxx = max(mxx, po[k].F);
                mxy = max(mxy, po[k].S);
            }
            ans = min(ans, max({mxx - mnx, mxy - mny, suf[j].mxx - suf[j].mnx, suf[j].mxy - suf[j].mny}));
        }
        ans = max(ans, 1);
        wrip(ans);
        putchar('\n');

    }
    return 0;
}
