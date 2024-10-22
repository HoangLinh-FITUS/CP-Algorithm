#include <bits/stdc++.h>
using namespace std;
long long gt(long long nn)
{
    if (nn == 0)
        return 1;
    return nn*gt(nn-1);
}
int main()
{
	freopen("RCSGT1.INP","r",stdin);
	freopen("RCSGT1.OUT","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    long long n;
    cin >> n;
    cout << gt(n);
    return 0;
}
    