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
template <ll __T> bitset <__T> bit(ll __N) { bitset <__T> __B(__N); return __B;}

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;

const ll Gmax = 2*1e5 + 1,mod = 1e9 + 7,oo = 1e18;

ll k;
ll cal(ll x,ll y)
{
    return (x+y)*(x-y);
}

int main()
{
   // inp;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> k;
    // k = (x+n)(x-n)
    // => k = x^2 - n^2 = > n^2 = x^2 - k;
    // => n = sqrt(x^2 - k)



    ll res(oo);
    fu(i,1,sqrt(abs(k))) if (k%i == 0)
    {
        ll y = (i*i - k)/(2*i);
        ll x = i - y;
        if (cal(x,y) == k) res = min(res,abs(x));
    }

    if (res == oo)
         cout << "none";
    else
        cout << res;
}
