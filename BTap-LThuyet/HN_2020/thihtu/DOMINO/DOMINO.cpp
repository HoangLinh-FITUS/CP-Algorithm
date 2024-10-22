#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "DOMINO"
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

const ll Gmax = 500 + 1,mod = 1e9 + 7,oo = 1e18;

struct data {ll x,y;};
ll a[Gmax][Gmax];
ll n,m;
data s;
ll res(0);

void quay(ll u,ll v,ll p)
{
    if (a[u][v] == 0)
    {
        if (p != -1) res++;
        if (u + 2 <= n && a[u + 1][v] == a[u + 2][v] && a[u + 2][v] != p)
        {
            a[u + 2][v] = 0;
            quay(u + 2,v,a[u + 1][v]);
            a[u + 2][v] = a[u + 1][v];
        }
        if (u - 2 > 0 && a[u - 1][v] == a[u - 2][v] && p != a[u - 2][v])
        {
            a[u - 2][v] = 0;
            quay(u - 2,v,a[u - 1][v]);
            a[u - 2][v] = a[u - 1][v];
        }
        if (v + 2 <= m && a[u][v + 2] == a[u][v + 1] && p != a[u][v + 1])
        {
            a[u][v + 2] = 0;
            quay(u,v + 2,a[u][v + 1]);
            a[u][v + 2] = a[u][v + 1];
        }
        if (v - 2 > 0 && a[u][v - 2] == a[u][v - 1] && a[u][v - 1] != p)
        {
            a[u][v - 2] = 0;
            quay(u,v - 2,a[u][v - 1]);
            a[u][v - 2] = a[u][v - 1];
        }
    }
}

int main()
{
    inp;
    out;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    fu(i, 1, (n * m - 1) / 2)
    {
        ll x,y,u,v;
        cin >> x >> y >> u >> v;
        a[x][y] = i;
        a[u][v] = i;
    }

    fu(i,1,n) fu(j,1,m) if (a[i][j] == 0) s = {i,j};

    quay(s.x,s.y,-1);

    cout << res;
}
