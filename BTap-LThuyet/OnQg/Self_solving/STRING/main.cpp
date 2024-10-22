#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "STRING"
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

const ll Gmax = 2*1e3 + 1,mod = 1e9 + 7,oo = 1e18;

string b[Gmax],s,t;
map <ii,ll> tick;
ll n,k;

bool check(string s,string st)
{
    ll cnt(0);
    fu(i,0,k-1) if (s[i] != st[i]) cnt++;
    return cnt == 1;
}

ll d[Gmax],f[Gmax];
vi a[Gmax];

void bfs(ll s)
{
    queue <ll> q;
    q.push(s);
    d[s] = 0;
    f[s] = 1;
    while (q.size())
    {
        ll u = q.front();
        q.pop();
        for(auto v:a[u])
        {
            if (d[v] == d[u] + 1) (f[v] += f[u])%=mod;
            if (!d[v])
            {
                d[v] = d[u] + 1;
                f[v] = f[u]%mod;
                q.push(v);
            }
        }
    }

    cout << d[n+1] << " " << f[n+1];
}

int main()
{
    inp;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> k >> s >> t;
    fu(i,1,n)  cin >> b[i];
    sort(b+1,b+n+1);
    b[0] = s,b[n+1] = t;
    fu(i,0,n+1) fu(j,0,n+1)
    if (i != j && tick[{i,j}] == 0 && check(b[i],b[j]))
    {
        tick[{i,j}] = 1;
        a[i].pb(j);
        a[j].pb(i);
    }
    bfs(0);
}
