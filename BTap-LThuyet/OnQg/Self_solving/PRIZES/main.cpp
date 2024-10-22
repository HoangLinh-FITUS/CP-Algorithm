#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "PRIZES"
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

template <class T> using Tree = tree<T,null_type,less<T>,tree_tag,tree_order_statistics_node_update>;

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;

const ll Gmax = 2*1e5 + 1,mod = 1e9 + 7,oo = 1e18;

ll f[Gmax],a[Gmax],d[Gmax],g[Gmax];
ll n,k;

ll cal(ll x,ll y)
{
    if (x > y) swap(x,y);
    return f[y] - f[x-1];
}

int main()
{
    inp;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> k;
    fu(i,1,n)
    {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }

    fu(i,1,n) d[i] = max(d[i-k],cal(i,i-k+1));
    fd(i,n,1) g[i] = max(g[i+k],cal(i,i+k-1));

    fu(i,1,n) cout << d[i] << " ";cout << endl;
    fu(i,1,n) cout << g[i] << " ";cout << endl;
    fu(i,1,n)


/*    ll Max = -oo,d,c;
    fu(i,1,n)
    {
        if (Max < cal(i,i-k+1))
        {
            Max = cal(i,i-k+1);
            d = i-k+1;
            c = i;
        }
    }

    fu(i,d,c) a[i] = 0;
    fu(i,1,n) f[i] = f[i-1] + a[i];
    Max = -oo;
    fu(i,1,n)
    {
        if (Max < cal(i,i-k+1))
            Max = cal(i,i-k+1);
    }
    cout << Max << '\n';
    */
}
