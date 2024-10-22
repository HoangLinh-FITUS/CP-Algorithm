#include <bits/stdc++.h>
using namespace std;
long long fibo(long long nn)
{
    if (nn == 0)
        return 0;
    if (nn == 1 || nn == 2)
    return 1;
    return fibo(nn-1) + fibo(nn-2);
}
int main()
{
	freopen("RCSFIBO1.INP","r",stdin);
	freopen("RCSFIBO1.OUT","w",stdout);
//    fibo(3) = fibo(2) + fibo(1) = 1 + 1 = 2;
    long long n;
    cin >> n;
    cout << fibo(n);
    return 0;
}