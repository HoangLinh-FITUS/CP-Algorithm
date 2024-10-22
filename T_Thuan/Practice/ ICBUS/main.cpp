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

template <typename T> inline void readln(T &x) {bool b = 0;char c;while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1;x = c - 48;while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48;if (b)x=-x;}
template <typename T> inline void writeln(T x) {if (x > 9) write(x / 10);putchar(x%10 + 48);}

template <class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <ll __T> bitset <__T> bit(ll __N) {
    bitset <__T> __B(__N);
    return __B;
}

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;

const ll Gmax = 2*1e5 + 1,mod = 1e9 + 7,oo = 1e18;
typedef ll m1c[Gmax];

vi a[Gmax];
ll n,k;
m1c c,d,dist;

struct data {
    ll x,y,z;
    bool operator < (const data &other) const
    {
        return other.y < y;
    }
};

void bfs() {
    fu(i,1,n) dist[i] = oo;
    priority_queue <data> q;
    q.push({1,c[1],d[1]}); // dinh -> coin -> cnt city

    dist[1] = c[1];

    while (!q.empty()) {
        data u = q.top();
        q.pop();
        if (dist[u.x] != u.y) continue;

        for(auto v:a[u.x]) {
            if (dist[v] > dist[u.x] + c[v]) {
                dist[v] == dist[u.x] + c[v];
                q.push({v,dist[v],d[v]});
            } else {
                q.push({v,u.y,u.z - 1});
            }
        }
    }

    fu(i,1,n) cout << dist[i] << " ";
    cout << endl;

}

int main() {
#ifdef HOFLIM
    inp;
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // HOFLIM

    readln(n);
    readln(k);
    fu(i,1,n) readln(c[i]),readln(d[i]);

    while (k--) {
        ll u,v;
        readln(u);readln(v);
        a[u].pb(v);
        a[v].pb(u);
    }
    bfs();
}
