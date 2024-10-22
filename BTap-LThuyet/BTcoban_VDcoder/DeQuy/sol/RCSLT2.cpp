#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;
long long power(long long x,long long y)
{
    if (y == 0)
    return 1;
    long long w = power(x,y/2);
    return (y%2 == 0)?((w%MOD*w%MOD)%MOD):(x%MOD*(w%MOD*w%MOD)%MOD)%MOD;
}
int main()
{
	freopen("RCSLT2.INP","r",stdin);
	freopen("RCSLT2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long a,b;
    cin >> a >> b;
    cout << power(a,b);
    return 0;
}
    