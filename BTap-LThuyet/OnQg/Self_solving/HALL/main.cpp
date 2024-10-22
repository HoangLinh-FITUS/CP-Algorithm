#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "HALL"
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

ll a,b,c,d;

int main()
{
    inp;
   // out;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> a >> b >> c >> d;
    ll res(0);
    fu(y,1,sqrt(b))
    {
        ll d = min(c/2 - y,a/y);
        ll c = min(d/2 - y,b/y);
        res += c-d+1;
    }
    cout << res;

}
