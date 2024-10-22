#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "MOVE"
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

ll n,s,t;
ll b[Gmax],d[Gmax];
ll trace[Gmax];
vii a[Gmax];

void bfs(ll s)
{
    queue <ll> q;
    q.push(s);
    d[s] = 1;

    ll Max = -oo;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        ll Min = oo,v;
        for(auto i:a[u])
        {
            ll uv = i.fi;
            if (d[i.se]) continue;
            if (Min > uv)
            {
                Min = uv;
                v = i.se;
            }
        }

        if (!d[v])
        {
            d[v] = 1;
            trace[v] = u;
            Max = max(Max,Min);
            q.push(v);
        }
    }

    cout << Max << '\n';
    vi res;
    while (t != s)
    {
        res.pb(t);
        t = trace[t];
    }
    res.pb(s);
    reverse(all(res));
    for(auto v:res) cout << v << " ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    inp;
    cin >> n >> s >> t;
    fu(i,1,n) cin >> b[i];
    ll u,v;
    while (cin >> u >> v)
    {
        ll w = abs(b[u] - b[v]);
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
    bfs(s);
}
