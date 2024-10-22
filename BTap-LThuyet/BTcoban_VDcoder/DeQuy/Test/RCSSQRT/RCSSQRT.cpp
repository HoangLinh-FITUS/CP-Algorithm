#include <bits/stdc++.h>
using namespace std;
float tong(long long n)
{
    if (n == 1)
        return 1;
    return sqrt(n+tong(n-1));
}
int main()
{
    long long n;
    cin >> n;
    printf("%0.3f",tong(n));
    return 0;
}
    