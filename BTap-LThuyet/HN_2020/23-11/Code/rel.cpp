#include <bits/stdc++.h>

#define task "REL"
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
const int N = 1002;
int n, low[N], num[N], ntar, dp[N], cc[N], ncc, in[N], ans[N];
vi scc[N], st;
vii g[N], gr[N];
void dfs(int u)
{
    in[u] = 1;
    st.eb(u);
    low[u] = num[u] = ++ntar;
    for (ii v : g[u])
    {
        if (!num[v.F]) dfs(v.F);
        if (in[v.F]) low[u] = min(low[u], low[v.F]);
    }
    if (low[u] == num[u])
    {
        ncc++;
        int v = 0;
        do
        {
            v = st.back();
            st.pop_back();
            in[v] = 0;
            cc[v] = ncc;
            scc[ncc].pb(v);
        } while (v != u);
    }
}
void topo(int u)
{
    in[u] = 1;
    for (ii v : gr[u]) if (!in[v.F]) topo(v.F);
    st.eb(u);
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    rep(i, 1, n) rep(j, 1, n)
    {
        int x;
        cin >> x;
        if (i == j) continue;
        if (x == 0)
        {
            g[i].eb(j, 0);
            g[j].eb(i, 0);
        }
        if (x == 1) g[j].eb(i, 1);
        if (x == -1) g[i].eb(j, 1);
        if (x == 2) g[j].eb(i, 0);
        if (x == -2) g[i].eb(j, 0);
    }
    rep(i, 1, n) if (!num[i]) dfs(i);
    rep(i, 1, ncc)
    {
//        cout << "SCC " << i << ": ";
//        for (int u : scc[i]) cout << u << ' ';
//        cout << '\n';
        vi change;
        for (int u : scc[i]) for (ii v : g[u]) if (cc[v.F] != i)
        {
            if (!in[cc[v.F]]) change.eb(cc[v.F]), in[cc[v.F]] = 1;
            if (v.S) in[cc[v.F]] = 2;
        }
        for (int v : change)
        {
            gr[i].eb(v, (in[v] == 2 ? 1 : 0));
            //cout << "Edge : " << i << ' ' << v << ' ' << (in[v] == 2 ? 1 : 0) << '\n';
            in[v] = 0;
        }
        change.clear();
    }
    rep(i, 1, ncc) if (!in[i]) topo(i);
    reverse(all(st));
    //PR(st, 0, ncc - 1);
    rep(i, 0, ncc - 1)
    {
        int u = st[i];
        dp[u] = max(dp[u], 1);
        for (ii v : gr[u]) dp[v.F] = max(dp[v.F], dp[u] + v.S);
    }
    rep(i, 1, ncc) for (int u : scc[i]) ans[u] = dp[i];
    rep(i, 1, n) cout << ans[i] << ' ';
    return 0;
}
