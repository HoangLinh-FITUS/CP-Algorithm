#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "inp"
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
#define eb emplace_back
#define se second
#define fi first
#define c_i(x) __builtin_popcount(x) // count bit 1
#define c_o(x) __builtin_ctz(x) // count bit 0
#define inp freopen(task".inp","r",stdin)
#define out freopen(task".out","w",stdout)

using ll = long long;
using ull = unsigned ll;
using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <ll __T> bitset <__T> bit(ll __N) {
    bitset <__T> __B(__N);
    return __B;
}

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;

const ll Gmax = 2*1e5 + 1,mod = 1e9 + 7,oo = 1e18;

string xau;
stack <string> q;
ll res(0);

int main() {
#ifdef HOFLIM
    inp;
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // HOFLIM

    cin >> xau;
    for(ll i = 0; xau[i]; i++) {
        string ST;
        ST = xau[i];
        q.push(ST);
        if (q.top() == ")") {
            string st = "";
            while (!q.empty() && q.top() != "(") {
                st = q.top() + st;
                q.pop();
            }
            st = q.top() + st;
            q.pop();
            while (!q.empty() && q.top() >= "0" && q.top() <= "9") {
                st = q.top() + st;
                q.pop();
            }
            ll so = 0;
            string sst = "";
            for(ll i = 0; st[i]; i++) {
                if (st[i] == '(' || st[i] == ')') continue;
                if (st[i] >= '0' && st[i] <= '9') so = so*10 + (st[i] - '0');
                else sst += st[i];
            }
            string y = "";
            fu(l,1,so) y = y + sst;
            q.push(y);
            res++;
        } else if (q.top() == "]") {
            string st = "";
            while (!q.empty() && q.top() != "[") {
                st = q.top() + st;
                q.pop();
            }
            st = q.top() + st;
            q.pop();
            if (st[1] == '*' && st[0] == '[') {
                string x = "";
                fu(i,2,st.size()-2) x += st[i];
                string y = x;
                reverse(all(y));
                q.push(x + y);
                res++;
            } else {
                st.erase(0,1);
                st.pop_back();
                st.pop_back();
                for(ll i = st.size()-2; i >= 0; i--) st += st[i];
                q.push(st);
                res++;
            }
        }
    }
    cout << res << '\n';
    vector <string> res;
    while (!q.empty()) {
        res.pb(q.top());
        q.pop();
    }
    for(auto it = res.rbegin(); it != res.rend(); it++) cout << *it;
}

