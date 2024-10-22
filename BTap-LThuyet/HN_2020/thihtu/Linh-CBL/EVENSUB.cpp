#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "EVENSUB"
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

ll n;
ll a[Gmax];

ll Max[Gmax][30];
ll Min[Gmax][30];

ll getmin(ll l,ll r)
{
    ll k = log2(r - l + 1);
    return min(Min[l][k],Min[r - (1 << k) + 1][k]);
}

ll getmax(ll l,ll r)
{
    ll k = log2(r - l + 1);
    return max(Max[l][k],Max[r - (1 << k) + 1][k]);
}

void trau()
{
    vi chan,le;
    fu(i,1,n)
    {
        ll x;
        cin >> x;
        Max[i][0] = Min[i][0] = x;
        if (x&1) chan.pb(x); else le.pb(i);
    }


    fu(k,1,ceil(log2(n))) for(ll i = 1; i + (1 << k) - 1 <= n; i++)
    {
        Max[i][k] = max(Max[i][k-1],Max[i + (1 << (k-1))][k-1]);
        Min[i][k] = min(Min[i][k-1],Min[i + (1 << (k-1))][k-1]);
    }

    ll res(0);
    fu(i,1,n) fu(j,i,n)
    {
        ll k = getmax(i,j) - getmin(i,j);
        if (k%2 == 0)
        {
            //cout << i << " " << j << endl;
            res++;
        }
    }
    cout << res;
}

int main()
{
    inp;
    out;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    trau();
}
