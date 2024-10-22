#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "smooth"
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

const ll Gmax = 5*1e3 + 1,mod = 1e9 + 7,oo = 1e18;

ll n,k,s;
ll a[Gmax],cntb[Gmax];
ll cnt[Gmax][Gmax];
ll f[Gmax][Gmax];

ll dq(ll i,ll s)
{
    if (i == k + 1 && s == 0) return 0;
    if (i == k + 1) return oo;
    ll &res = f[i][s];
    if (res != -1) return res;
    res = oo;
    fu(x,0,s)
        res = min(res,dq(i+1,s - x) + cntb[i] - cnt[i][x]);
    return res;
}

int main()
{
    inp;
    out;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> k >> s;
    fu(i,1,n) cin >> a[i];

    fu(i,1,k) for(ll j = i; j <= n; j += k) cnt[i][a[j]]++,cntb[i]++;

    memset(f,-1,sizeof(f));
    cout << dq(1,s);

}
