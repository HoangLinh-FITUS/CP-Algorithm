#include <bits/stdc++.h>
using namespace std;
long long n;
string ok;
void tinh(long long nn)
{
    if (nn == 0)
    {
        ok = "No";
        return;
    }
    if (nn == 1)
    {
        ok = "Yes";
        return;
    }
    if (nn % 10 == 0)
        tinh(nn/10);
    if (nn % 20 == 0)
        tinh(nn/20);
}
int main()
{
    freopen("RCSHACK.INP","r",stdin);
    freopen("RCSHACK.OUT","w",stdout);
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ok = "No";
        tinh(n);
        cout << ok << endl;
    }
    return 0;
}
