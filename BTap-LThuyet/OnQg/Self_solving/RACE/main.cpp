#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "RACE"
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

vi a[Gmax];
ll low[Gmax],num[Gmax];
ll n,m,cnt(0);
map <ii,ll> dd;
vi res;

void tarjan(ll u,ll p) {
    low[u] = num[u] = ++cnt;

    for(auto v:a[u])
        if (v != p) {
            if (num[v]) low[u] = min(low[u],num[v]);
            else {
                tarjan(v,u);
                low[u] = min(low[u],low[v]);
                if (low[v] > num[v])
                {
                    if (dd[{u,v}]) res.pb(v);//cout << v << " ";
                    else res.pb(u);

                }
            }
        }
}

int main() {
    //inp;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        ll u,v,w;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
        dd[{u,v}] = 1;
    }

    fu(i,1,n) if (!num[i]) tarjan(i,i);
    cout << res.size() << '\n';
    sort(all(res));
    for(auto v:res) cout << v << " ";
}
