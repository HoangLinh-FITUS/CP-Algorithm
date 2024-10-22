#include <bits/stdc++.h>

#define task "K"
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
const int N = 5002;
int T, n, m, cnt[N], K;
ll d[N];
vii g[N];
void solve()
{
    cin >> n >> m;
    rep(i, 1, n) g[i].clear();
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
    }
    cin >> K;
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push({0, 1});
    fill(cnt + 1, cnt + 1 + n, 0);
    fill(d + 1, d + 1 + n, -1);
    while (!pq.empty())
    {
        int u = pq.top().S;
        ll du = pq.top().F;
        pq.pop();
        if (du != d[u]) cnt[u]++;
        if (cnt[u] > K) continue;
        d[u] = du;
        if (u == n && cnt[u] == K)
        {
            cout << du << '\n';
            return;
        }

        for (ii v : g[u]) pq.push({du + v.S, v.F});
    }
    cout << "-1\n";
}
int main()
{
#ifdef HynDuf
    freopen(task".in", "r", stdin);
    //freopen(task".out", "w", stdout);
#else
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif
    cin >> T;
    while (T--) solve();
    return 0;
}
