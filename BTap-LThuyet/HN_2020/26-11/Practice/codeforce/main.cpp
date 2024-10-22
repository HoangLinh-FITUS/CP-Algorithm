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
ii a[Gmax];

void test();

ll coin(ll x,ll y) {
    if (y > x) return y - x + 1;
    if (x > y) return n - x + y;
}

ll f[Gmax];

void solve() {
    fu(i,1,n) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a+1,a+n+1);

    fu(i,1,n) cout << a[i].fi << " " << a[i].se << endl;
    cout << endl;

    fu(i,1,n)
    {
        if (a[i].fi == 1) continue;
        ll x = lower_bound(a+1,a+n+1,ii(a[i].fi-1,a[i].se)) - a - 1;
        ll y = upper_bound(a+1,a+n+1,ii(a[i].fi-1,a[i].se)) - a;
        cout << a[i].fi << " " << a[i].se << endl;
        cout << a[x].fi << " " << a[x].se << endl;
        cout << a[y].fi << " " << a[y].se << endl;
        system("pause");
        f[i] = f[x] + coin(a[x].se,a[i].se);
        f[i] = min(f[i],f[y] + coin(a[y].se,a[i].se));
    }

    fu(i,1,n) cout << f[i] << " ";cout << endl;
}

int main() {
    inp;
    //out;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    //test();
    solve();
}

void test() {
    ll a[Gmax];
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

        while (c != k + 1) {
            fu(j,1,n) {
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
