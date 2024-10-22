#include <bits/stdc++.h>

#define task "LAUGH"
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
int n, dp[100002];
string s;
map<char, int> mp;
struct Node
{
    int son[4];
    bool leaf;
    Node() {fill(son, son + 4, 0); leaf = 0;}
};
vector<Node> trie(1, Node());
void add(const string &s)
{
    int u = 0;
    rep(i, 0, SZ(s) - 1)
    {
        if (!trie[u].son[mp[s[i]]])
        {
            trie[u].son[mp[s[i]]] = SZ(trie);
            trie.pb(Node());
        }
        u = trie[u].son[mp[s[i]]];
    }
    trie[u].leaf = 1;
}

int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> s;
    s = '0' + s;
    mp['a'] = 0;
    mp['b'] = 1;
    mp['c'] = 2;
    mp['h'] = 3;
    rep(i, 1, n)
    {
        string t;
        cin >> t;
        reverse(all(t));
        add(t);
    }
    int ans = 0;
    rep(i, 1, SZ(s) - 1)
    {
        int u = 0;
        Rep(j, i, max(1, i - 29))
        {
            if (!trie[u].son[mp[s[j]]]) break;
            u = trie[u].son[mp[s[j]]];
            if (trie[u].leaf)
            {
                if (dp[j - 1]) dp[i] = dp[j - 1];
                else dp[i] = j;
            }
        }
        if (dp[i]) ans = max(ans, i - dp[i] + 1);
    }
    cout << ans;
    return 0;
}
