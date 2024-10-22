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
typedef pair<ll, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
const int N = 2502;
int n, m, d[N];
vi in[N], s[N << 1];
bool done[N << 1];
int main()
{
#ifdef HynDuf
    freopen(task".in", "r", stdin);
    //freopen(task".out", "w", stdout);
#else
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif
    cin >> n >> m;
    rep(i, 0, m - 1)
    {
        int len;
        cin >> len;
        s[i].assign(len, 0);
        rep(j, 0, len - 1)
        {
            int u;
            cin >> u;
            in[u].eb(i);
            s[i][j] = u;
        }
    }
    ll ans = 0;
    rep(i, 0, n - 1)
    {
        queue<int> q;
        q.push(i);
        fill(d, d + n, -1);
        fill(done, done + m, 0);
        d[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans += d[u];
            for (int id : in[u]) if (!done[id])
            {
                done[id] = 1;
                for (int v : s[id]) if (d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    assert(ans % 2 == 0);
    cout << ans / 2;
    return 0;
}
