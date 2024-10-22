#include <bits/stdc++.h>

#define task "FIELD"
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
const int N = 1e3 + 2;
int n, m, a[N][N];
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> a[i][j];
    int A = -m, B = n, ans = 0;
    rep(i, 0, n - 1) rep(j, 0, m - 1) if (a[i][j])
    {
        if ((A * i + B * j) * 1LL * (A * (i + 1) + B * (j + 1)) < 0) ans++;
        else if ((A * (i + 1) + B * j) * 1LL * (A * i + B * (j + 1)) < 0) ans++;
    }
    cout << ans;
    return 0;
}
