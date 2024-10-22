#include <bits/stdc++.h>
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define se second
#define fi first
#define SZ(O_O) O_O.size()
#define all(O_O) O_O.begin(),O_O.end()
#define inp freopen(task".inp","r",stdin)
#define out freopen(task".out","w",stdout)
#define task "monument"

using ll = long long;
using namespace std;

typedef pair<ll,ll> ii;
typedef vector <ll> vi;
typedef vector <ii> vii;


const ll Gmax = 2*1e5 + 1,oo = 1e18;

ll n,cnt(0);
ii a[Gmax];
vi com;
ll BIT[Gmax],dd[Gmax],f[Gmax];

ll get(ll p)
{
    ll s = 0;
    for(; p; p -= p & -p) s = max(s,BIT[p]);
    return s;
}

void update(ll p,ll value)
{
    for(; p <= cnt; p += p & -p) BIT[p] = max(BIT[p],value);
}

ll F[Gmax];
ll b[Gmax];
ll kt[Gmax];

bool ss(ii x,ii y)
{
    if (x.fi == y.fi) return x.se > y.se;
    return x.fi < y.fi;
}

int main()
{
    inp;
    out;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    //out;srand(time(NULL));n = rand()%10 + 1;fu(i,1,n){a[i].fi = rand()%10 + 1;a[i].se = rand()%20 + 1;}
    cin >> n;fu(i,1,n) cin >> a[i].fi >> a[i].se;

    sort(a+1,a+n+1,ss);

    fu(i,1,n) com.pb(a[i].se);
    sort(all(com));
    com.erase(unique(all(com)),com.end());
    cnt = 0;
    for(auto v:com) dd[v] = ++cnt;

    fu(i,1,n) f[i] = f[i-1] + a[i].se;

    fu(i,1,n) b[i] = a[i].fi;

    fu(i,1,n)
    {
       ll sum = get(dd[a[i].se] - 1);

       update(dd[a[i].se],a[i].se + sum);
    }

    cout << get(cnt) << endl;
    /*ll res = 0;
    fu(i,1,n)
    {
        F[i] = a[i].se;
        fd(j,i-1,1) if (a[i].fi > a[j].fi && a[i].se > a[j].se) F[i] = max(F[i],F[j] + a[i].se);
        res = max(res,F[i]);
    }cout << res;*/
}
