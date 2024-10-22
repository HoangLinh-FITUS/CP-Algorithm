#include <bits/stdc++.h>

#define task "Str2n"
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
const int N = 1e6 + 2;
struct Node
{
    int son[26];
    vi ed;
    Node() {fill(son, son + 26, 0);}
};
vector<Node> trie(1, Node());
int n, pos[N];
void add(const string &s, int id)
{
    int u = 0;
    rep(i, 0, SZ(s) - 1)
    {
        if (!trie[u].son[s[i] - 'a'])
        {
            trie[u].son[s[i] - 'a'] = SZ(trie);
            trie.pb(Node());
        }
        u = trie[u].son[s[i] - 'a'];
    }
    pos[id] = u;
    trie[u].ed.pb(id);
}
vi st;
vii ans;
void dfs(int u)
{
    for (int id : trie[u].ed) st.pb(id);
    rep(i, 0, 25) if (trie[u].son[i]) dfs(trie[u].son[i]);
    while (!st.empty() && pos[st.back()] == u)
    {
        int tmp = st.back();
        st.pop_back();
        ans.eb(tmp, st.back());
        st.pop_back();
    }
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    rep(i, 1, 2 * n)
    {
        string s;
        cin >> s;
        add(s, i);
    }
    dfs(0);
    for (ii v : ans) cout << v.F << ' ' << v.S << '\n';
    return 0;
}
