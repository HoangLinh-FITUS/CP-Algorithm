#include <bits/stdc++.h>
using namespace std;
vector <long long> b,a;
long long n = 0;
string ok = "NO";
void tim(long long x,long long y)
{
    if (x == y)
        ok = "YES";
    if (x <= y)
    {
        b.push_back(x);
    }
    if (x*2 <= y)
        tim(x*2,y);
    if (x*10 + 1 <= y)
        tim(x*10+1,y);
}
int main()
{
    freopen("RCSCONVC.INP","r",stdin);
    freopen("RCSCONVC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long x,y;
    cin >> x >> y;
    tim(x,y);
    if (ok == "NO")
    {
        cout << ok;
        exit(0);
    }
    cout << ok << endl;
    sort(b.begin(),b.end());
    a.push_back(y);
    while (y!= x)
    {
        for (long long i = 0; i < b.size(); i++)
        {
            if (y/2 == b[i] && y%2 == 0)
            {
                y/=2;
                a.push_back(y);
                break;
            }
            if ((y-1)/10 == b[i] && (y-1)%10 == 0)
            {
                y = (y-1)/10;
                a.push_back(y);
                break;
            }
        }
    }
    cout << a.size() << endl;
    for (long long i = a.size()-1; i > -1; i--)
        cout << a[i] << " ";
    return 0;
}
