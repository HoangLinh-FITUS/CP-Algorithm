#pragma GCC opminize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') c = getchar(), b = 1;
    x = c - 48;
    while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48;
    if (b)x=-x;
}
template <typename T> inline void write(T x) {
    if (x > 9) write(x / 10);
    putchar(x%10 + 48);
}


typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<ii,ll> iii;

const ll Gmax = 2*1e6 + 1,mod = 1e9 + 7,oo = 1e18;

iii a[Gmax];
ll n,k;
ll f[Gmax];

int main() {
#ifdef HOFLIM
    inp;
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // HOFLIM
    read(n);
    read(k);
    fu(i,1,n) {
        read(a[i].fi.fi);
        read(a[i].fi.se);
        read(a[i].se);
        a[i].fi.se += a[i].fi.fi + k - 1;
    }

    sort(a+1,a+n+1,[&](const iii &x,const iii &y) {
        return x.fi.se < y.fi.se;
    });

    ll res(0);
    fu(i,1,n) {
        ll l = 1,r = i-1;
        while (l <= r) {
            ll g = (l+r)>>1;
            if (a[g].fi.se >= a[i].fi.fi)
                r = g - 1;
            else
                l = g + 1;
        }
        f[i] = max(f[i-1],a[i].se);
        if (r > 0) f[i] = max(f[i],f[r] + a[i].se);
    }
    write(*max_element(f+1,f+n+1));

}
