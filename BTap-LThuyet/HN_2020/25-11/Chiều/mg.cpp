#include <bits/stdc++.h>

#define task "M"
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
typedef pair<ll, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
const int N = 1002;
int n, S, T, m, a[N], b[N], d[N];

int main()
{
#ifdef HynDuf
    freopen(task".in", "r", stdin);
    //freopen(task".out", "w", stdout);
#else
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif
    cin >> n >> S >> T >> m;
    rep(i, 1, m) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    fill(d + 1, d + 1 + m, -1);
    queue<int> q;
    rep(i, 1, m) if (S % a[i] == 0) q.push(i), d[i] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (T % b[u] == 0)
        {
            cout << d[u] + 1;
            return 0;
        }
        rep(i, 1, m) if (i != u && d[i] == -1)
        {
            ll lcm = b[u] * 1LL * a[i] / __gcd(a[i], b[u]);
            if (lcm <= n)
            {
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }
    cout << -1;
    return 0;
}
