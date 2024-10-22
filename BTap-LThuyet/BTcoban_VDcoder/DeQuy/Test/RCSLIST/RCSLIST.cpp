#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;
const int N = 1e4;

int n,l = 0;
bool d[N];
ll a[N],b[N];

void dq(int i,int dem, ll x)
{
    if (dem == n) return;
    b[++l] = x;
    for(int j = 1; j <= n; j++)
        if (d[j] == 0 && j != i)
    {
        if (a[j] == x/3 || a[j] == x*2)
        {
            d[j] = 1;
            dq(i,dem+1,a[j]);
            return;
        }
    }
}

int main()
{
    freopen("RCSLIST.INP","r",stdin);
    freopen("RCSLIST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        l = 0;
        fill(d + 1,d + 1 + n,0);
        dq(i,0,a[i]);
        if (l == n) {
            for(int k = 1; k <= n; k++) cout << b[k] << " ";
            return 0;
        }
    }
    return 0;
}
