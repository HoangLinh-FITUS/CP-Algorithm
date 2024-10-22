#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "TANK"
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
template <ll __T> bitset <__T> bit(ll __N) { bitset <__T> __B(__N); return __B;}

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;

const ll Gmax = 2*1e5 + 1,mod = 1e9 + 7,oo = 1e18;

ll f[Gmax];
ll a[Gmax];
ll n,m;

bool check(ll L)
{
    fu(i,1,n - L + 1) if (f[L + i - 1] - f[i-1] < m) return 0;
    return 1;
}

ll test()
{
    ll res = oo;
    fu(i,1,n) if (check(i)) res = min(res,i);
    return res;
}

int main()
{
    inp;
    out;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> m >> n;
    fu(i,1,n)
    {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    ll res = oo;
    ll l = 1,r = n;
    while (l <= r)
    {
        ll x = (l + r) >> 1;
        if (check(x))
            r = x - 1;
        else
            l = x + 1;
    }

    cout << l;
}
