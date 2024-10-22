#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "SPECIAL"
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

ll n;
ll a[Gmax],dd[Gmax];
ll f[Gmax],trace[Gmax];

int main()
{
    inp;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    fu(i,1,n) cin >> a[i];

    ll position = 0,res(0);
    fu(i,1,n)
    {
        f[i] = 1;
        fd(j,i-1,1) if (a[i] > a[j] && f[i] < f[j] + 1)
        {
            f[i] = f[j] + 1;
            trace[i] = j;
        }
        if (res < f[i])
        {
            res = f[i];
            position = i;
        }
    }

    while (position != 0)
    {
        dd[position] = 1;
        position = trace[position];
    }

    fu(i,1,n) fu(j,i+1,n) if (a[i] < a[j] && f[i] == f[j] - 1 && dd[j] == 1) dd[i] = 1;

    vi Res;
    fu(i,1,n) if (dd[i]) Res.pb(a[i]);
    sort(all(Res));
    for(auto v:Res) cout << v << " ";
}
