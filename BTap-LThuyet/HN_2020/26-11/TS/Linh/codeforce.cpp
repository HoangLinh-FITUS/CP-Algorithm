#include <bits/stdc++.h>
#define task "codeforce"
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define inp freopen(task".INP","r",stdin)
#define out freopen(task".OUT","w",stdout)
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()

using ll = long long;
using namespace std;

typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector <ll> vi;
typedef vector<ii> vii;
typedef vector <iii> viii;

const ll Gmax = 2*1e5 + 1,oo = 1e18;

ll n,k;
//ii a[Gmax];
ll a[Gmax];

/*ll Find(ll x,ll y,ii key) {
    ll l = x,r = y;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g].fi > key.fi && a[g].se > key.se)
            r = g - 1;
        else l = g + 1;
    }
    return r + 1;
}

ll cal(ll x,ll y) {
    if (y > x) return y - x;
    else if (x > y) return n - y + x - 1;
}

ll f[Gmax];
*/

void test() {
    fu(i,1,n) cin >> a[i];

    ll ans = oo;
    fu(i,1,n)
    if (a[i] == 1) {
        ll c = 2,res = 1;
        fu(j,i+1,n) {
            res++;
            if (a[j] == c) c++;
            if (c == k+1) break;
        }

        while (c != k + 1)
        {
            fu(j,1,n)
            {
                res++;
                if (a[j] == c) c++;
                if (c == k + 1) break;
            }
        }
        ans = min(ans,res);

        //break;
    }
    cout << ans;
}

int main() {
    inp;
    out;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    test();

    /*fu(i,1,n) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a+1,a+n+1);

    fu(i,1,n) cout << a[i].fi << " " << a[i].se << endl;
    cout << endl;

    fu(i,1,n) if (a[i].fi > 1) f[i] = oo;

    fu(i,1,n) {

        ll x = Find(1,n,a[i]);
        ll y = upper_bound(a+1,a+n+1,ii(a[i].fi,oo)) - a;

        //cout << i << " " << x << " " << y << " " << a[x].se << " " << a[y].se << endl;

        if (a[i].fi == a[x].fi - 1) f[x] = min(f[x],f[i] + cal(a[i].se,a[x].se));
        if (a[i].fi == a[y].fi - 1) f[y] = min(f[y],f[i] + cal(a[i].se,a[y].se));

    }

    ll res = oo;

    fu(i,1,n) cout << f[i] << " ";cout << endl;
    fu(i,1,n) if (a[i].fi == k) res = min(res,f[i]);//cout << f[i] << " ";cout << endl;
    cout << res - 1;
    */
}
