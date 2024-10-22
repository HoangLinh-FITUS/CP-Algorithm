#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "RICEATM"
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

ll n;
ii a[Gmax];
ll f[Gmax];
ll res[Gmax];

int main() {

    inp;
    out;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    fu(i,1,n) cin >> a[i].fi >> a[i].se;
    memset(f,0,sizeof(f));

    fd(i,n,1) f[i] = min(f[i+1] + a[i].fi,f[i+2] + a[i].se);
    cout << f[1] << '\n';

    fu(i,1,n) if (f[i] == f[i + 1] + a[i].fi) res[i] = 1; else res[i] = 2, res[i + 1] = 0, i++;

    fu(i,1,n) cout << res[i] << " ";
}
