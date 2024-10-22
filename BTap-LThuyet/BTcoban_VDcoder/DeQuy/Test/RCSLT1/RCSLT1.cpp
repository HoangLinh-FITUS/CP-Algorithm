#include <bits/stdc++.h>
using namespace std;
long long power(long long a,long long b)
{
    if (b == 0)
        return 1;
    long long w = power(a,b/2);
    return (b%2 == 0) ?(w*w):(w*w*a);
}
int main()
{
    freopen("RCSLT1.inp","r",stdin);
    freopen("RCSLT1.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long x,n;
    cin >> x >> n;
    cout << power(x,n);
    return 0;
}
    