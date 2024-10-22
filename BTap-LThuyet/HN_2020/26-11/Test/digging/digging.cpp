//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long
#define Task "digging"

using namespace std;

int n, a[maxn];
long long sum[maxn], T;

ll Get(int len, ll xmin){
    double p = (double)len * xmin + 1ll*len*(len-1)/2;
    if (abs(p) > 4e18) return -4e18;
    return xmin*len + 1ll*len*(len-1)/2;
}

bool check(ll h)
{
    int L = 1, R = 1;
    for (int x = 1; x <= n; x++){
        while (h+x-L > a[L]) L++;
        while (R < n && h+R+1-x <= a[R+1]) R++;
        ll curT = sum[R] - sum[L-1] - Get(x-L+1, h) - Get(R-x, h+1);
        if (curT <= T) return 1;
    }
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> T;
    long long res = 1e9;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i];
    long long L = -T, R = *min_element(a+1, a+n+1);
    while (R - L > 1){
        ll mid = (L+R)/2;
        if (check(mid)) R = mid;
            else L = mid;
    }
    cout << R;
    return 0;
}

