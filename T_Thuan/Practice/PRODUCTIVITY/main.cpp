#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define task "inp"
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
template <ll __T> inline bitset <__T> bit(ll __N) {
    bitset <__T> __B(__N);
    return __B;
}

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;

const ll Gmax = 1e3 + 1,mod = 1e9 + 7,oo = 1e18;

ll s[Gmax][Gmax];
ll n;
ll f[21][1 << 21];

ll n, m, Assigned[N];
ll Visited[N], t = 0;
vector <ll> a[N];

bool visit(ll u) {
    if (Visited[u] != t)
        Visited[u] = t;
    else
        return false;

    for (ll i = 0; i < a[u].size(); i++) {
        ll v = a[u][i];
        if (!Assigned[v] || visit(Assigned[v]) && s[i][j]) {
            Assigned[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    inp;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    fu(i,1,n) fu(j,1,n) cin >> s[i][j];
    int Count = 0;
    for (int i = 1; i <= n; i++) {
        t++;
        Count += visit(i);
    }
}
/*
ll dq(ll i,ll mask)
{
    if (mask == ((1 << (n+1)) - 1) - 1) return oo;
    ll res(0);
    if (f[i][mask] != -1) return f[i][mask];
    fu(j,1,n) if ((mask&(1 << j)) == 0)
    {
        ll x = min(dq(i+1,mask|(1 << j)),a[i][j]);
        res = max(res,x);
    }
    return f[i][mask] = res;
}

int main() {
#ifdef HOFLIM
    inp;
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // HOFLIM

    cin >> n;
    fu(i,1,n) fu(j,1,n)
        cin >> a[i][j];

    memset(f,-1,sizeof(f));

    cout << dq(1,0);

}
*/
