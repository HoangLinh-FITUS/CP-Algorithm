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
	freopen("RCSSUM.INP","r",stdin);
	freopen("RCSSUM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    cout << tong(n);
    return 0;
}
