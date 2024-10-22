#include <bits/stdc++.h>
#define ll long long
#define MAC (ll)1e7
#define fu(i,a,b) for (ll i = a; i <= b; i++)
using namespace std;

ll n,a[MAC],b[MAC];

ll dq(ll ii)
{
    b[a[ii]]++;
    if (b[a[ii]] == 2) return a[ii];
    return dq(a[ii]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RCSBADGE.INP","r",stdin);
    freopen("RCSBADGE.OUT","w",stdout);
    cin >> n;
    fu (i,1,n)
    cin >> a[i];
    fu (i,1,n)
    {
        fill(b+1,b+1+n,0);
        b[i] = 1;
        cout << dq(i) << " ";
    }
    return 0;
}
