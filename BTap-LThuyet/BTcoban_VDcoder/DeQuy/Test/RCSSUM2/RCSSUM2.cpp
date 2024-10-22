#include <bits/stdc++.h>
using namespace std;
long long n;
long long tong(long long nn)
{
    if (nn == 0)
        return 0;
    return nn%10 + tong(nn/10);
}
int main()
{
	freopen("RCSSUM2.INP","r",stdin);
	freopen("RCSSUM2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    long long nn = tong(n);
    while (nn/10 != 0)
    {
        nn = tong(nn);
    }
    cout << nn;
    return 0;
}
    