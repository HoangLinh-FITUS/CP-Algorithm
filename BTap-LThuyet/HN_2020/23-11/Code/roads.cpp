#include <bits/stdc++.h>

#define task "roads"
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
typedef vector<iii> viii;
typedef vector<ll> vl;
const int N = 1e5 + 2;
int n, m, S, T;
viii g[N];
map<int, ii> par[N];
viii edge;
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> S >> T;
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({{v, w}, i});
        g[v].pb({{u, w}, i});
        edge.pb({{u, v}, w});
    }
    queue<ii> q;
    q.push({S, 0});
    par[S][0] = {0, 0};
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        if (u.F == T)
        {
            vi ans;
            int ver = T, cur = u.S;
            while (ver != S)
            {
                ii it = par[ver][cur];
                ver = (edge[it.F - 1].F.F == ver ? edge[it.F - 1].F.S : edge[it.F - 1].F.F);
                cur = it.S;
                ans.eb(it.F);
            }
            cout << SZ(ans) << '\n';
            Rep(i, SZ(ans) - 1, 0) cout << ans[i] << ' ';
            return 0;
        }
        viii change;
        for (iii v : g[u.F]) if (v.F.S != u.S)
        {
            if (par[v.F.F].find(v.F.S) == par[v.F.F].end()) par[v.F.F][v.F.S] = {v.S, u.S}, q.push({v.F.F, v.F.S});
        } else change.pb(v);
        g[u.F] = change;
    }
    cout << -1;
    return 0;
}
