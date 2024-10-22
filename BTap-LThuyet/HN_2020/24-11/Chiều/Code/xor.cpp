#include <bits/stdc++.h>

#define task "XOR"
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
struct Node
{
    int son[2];
    Node() {son[0] = son[1] = 0;}
};
vector<Node> trie;
void add(int x)
{
    int u = 0;
    Rep(i, 29, 0)
    {
        if (!trie[u].son[x >> i & 1])
        {
            trie[u].son[x >> i & 1] = SZ(trie);
            trie.pb(Node());
        }
        u = trie[u].son[x >> i & 1];
    }
}
int query(int x)
{
    int u = 0, res = 0;
    Rep(i, 29, 0)
    {
        int nxt = ((x >> i & 1) ? 0 : 1);
        if (!trie[u].son[nxt]) u = trie[u].son[nxt ^ 1];
        else res += (1 << i), u = u = trie[u].son[nxt];
    }
    return res;
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        trie = vector<Node> (1, Node());
        int ans = 0;
        rep(i, 1, n)
        {
            int x;
            cin >> x;
            ans = max(ans, query(x));
            add(x);
        }
        cout << ans << '\n';
    }
    return 0;
}
