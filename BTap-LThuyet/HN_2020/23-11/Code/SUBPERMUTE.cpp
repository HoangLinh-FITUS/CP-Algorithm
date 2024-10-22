#include <bits/stdc++.h>

#define task "SUBPERMUTE"
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
const int N = 1e5 + 2;
int n, K, T, a[N], lst[N], ans[N];
bool done[N];
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> K;
        fill(done + 1, done + 1 + K, 0);
        rep(i, 1, n)
        {
            cin >> a[i];
            lst[a[i]] = i;
        }
        set<int> s;
        priority_queue<ii, vii, greater<ii> > pq;
        rep(i, 1, K) s.insert(lst[i]);
        int ilst = 0, cur = 0;
        rep(I, 1, K)
        {
            rep(i, ilst + 1, *s.begin()) pq.push({a[i], i});
            ilst = *s.begin();
            while (!pq.empty() && (pq.top().S <= cur) || done[pq.top().F]) pq.pop();
            assert(!pq.empty());
            ii it = pq.top();
            pq.pop();
            done[it.F] = 1;
            cur = it.S;
            ans[I] = it.F;
            s.erase(lst[it.F]);
        }
        rep(i, 1, K) cout << ans[i] << " \n"[i == K];
    }
    return 0;
}
