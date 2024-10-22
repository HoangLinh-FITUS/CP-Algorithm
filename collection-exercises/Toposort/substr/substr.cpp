#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i = a; i <= b; i++)
#define Fd(i,a,b) for(ll i = a; i >= b; i--)
#define task "D"
#define ii pair<ll,ll>
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define DB(x) cerr << #x << " = " << x << '\n'
#define DB2(a,i,j) cerr << #a << "[" << i << "," << j << "] = " << a[i][j] << '\n'
#define DB1(a,i) cerr << #a << "[" << i << "] = " << a[i] << '\n'
#define DB3(a,i,j,k) cerr << #a << "[" << i << "," << j << "," << k << "] = " << a[i][j][k] << '\n'
#define vi vector <ll>
#define max(...) max({__VA_ARGS__})
#define min(...) min({__VA_ARGS__})
#define bit(mask) bitset <10>(mask)

const ll INF = 1e18;
const ll mod = 1e9 + 7;
const ll N = 3e5 + 1;
typedef ll Array[N];

using namespace std;

ll n,m;
char s[N];
vi a[N],topo;
Array dd;

void dfs_topo(ll u)
{
        dd[u] = 1;
        for(auto v : a[u]) if (!dd[v]) dfs_topo(v);
        else if (dd[v] == 1) {cout << -1;exit(0);};
        dd[u] = 2;
        topo.pb(u);
}

int main()
{
        if (fopen(task".inp","r")) freopen(task".inp","r",stdin);
    	ios::sync_with_stdio(false);
    	cin.tie(0);
        cin >> n >> m >> (s + 1);
        while (m--)
        {
                ll u,v;
                cin >> u >> v;
                a[u].pb(v);
        }
        For(i,1,n) if (!dd[i]) dfs_topo(i);
        reverse(all(topo));
        vector <vi> dp(n + 1,vi(26,0));
        for(auto i : topo) dp[i][s[i] - 'a'] = 1;
        for(auto u : topo)
        {
                for(auto v : a[u])
                {
                        For(c,0,25)
                        {
                                dp[v][c] = max(dp[v][c],dp[u][c] + (c == s[v] - 'a'));
                        }
                }
        }
        ll res = 0,cnt = 0;
        For(i,1,n) For(j,0,25) res = max(res,dp[i][j]);
        cout << res;

}