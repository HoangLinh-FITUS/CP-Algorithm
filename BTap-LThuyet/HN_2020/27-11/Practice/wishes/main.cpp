#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "wishes"
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

const ll Gmax = 2*1e7 + 1,mod = 1e9 + 7,oo = 1e18;

ll power(ll x,ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    ll w = power(x,y/2);
    if (y&1) return w*w*x;
    return w*w;
}

ll cal(ll x,ll y) {
    return (power(x,y+1) - 1)/(x-1);
}

ll uoc(ll N) {
    ll s = 1;
    fu(i,2,N) if (N%i == 0) {
        ll cnt(0);
        while (N%i == 0) N /= i,cnt++;
        s *= cal(i,cnt);
    }
    return s;
}

ll l,r;

ll solve(ll n) {
    ll sum = 0;

    for (ll l = 1; l <= n;) {
        ll r = n / floor(n / l);
        ll x = (((r % mod) * ((r + 1)% mod))/ 2)% mod;
        ll y = (((l % mod) * ((l - 1)% mod))/ 2)% mod;
        ll p = ((n / l) % mod);
        sum = (sum + (((x - y) % mod) * p) % mod+ mod)% mod;
        sum %= mod;
        l = r + 1;
    }
    return (sum + mod)%mod;
}

int main() {
    inp;
    out;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> r;
    cout << (solve(r) - solve(l-1))%mod;
}
