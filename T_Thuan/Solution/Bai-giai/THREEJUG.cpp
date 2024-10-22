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

ll A,B,C,a,b,c,T,d;

int main() {
#ifdef HOFLIM
    inp;
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // HOFLIM

    cin >> A >> B >> C >> a >> b >> c >> d >> T;
    if (a + b + c < T) return cout << -1,0;

    ll x = a/d;
    ll X = (A-a)/d;
    ll y = b/d;
    ll Y = (B-b)/d;
    ll z = c/d;
    ll Z = (C - c)/d;
    ll ans = 1e9;

    if (T <= A && T % d == a % d) {
        if (T >= a && (T - a) / d <= y + z) ans = min(ans, (T - a) / d);
        if (T < a && (a - T) / d <= Y + Z) ans = min(ans, (a - T) / d);
    }
    if (T <= B && T % d == b % d) {
        if (T >= b && (T - b) / d <= x + z) ans = min(ans, (T - b) / d);
        if (T < b && (b - T) / d <= X + Z) ans = min(ans, (b - T) / d);
    }
    if (T <= C && T % d == c % d) {
        if (T >= c && (T - c) / d <= x + y) ans = min(ans, (T - c) / d);
        if (T < c && (c - T) / d <= Y + X) ans = min(ans, (c - T) / d);
    }
    if (ans == 1e9) cout << -1;
    else
        cout << ans;
}
