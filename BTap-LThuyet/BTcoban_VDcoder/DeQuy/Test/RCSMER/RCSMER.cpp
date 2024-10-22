#include <bits/stdc++.h>
using namespace std;
string s2,s1,MAX = "0", MIN = "99999999999999999999999999";
void tinh(string x,string y,long long i,long long j,string c)
{
    if (c.size() == x.size() + y.size())
    {
        MAX = max(MAX,c);
        MIN = min(MIN,c);
    }
    if (i < x.size())
        tinh(x,y,i+1,j,c+x[i]);
    if (j < y.size())
        tinh(x,y,i,j+1,c+y[j]);
}
int main()
{
    freopen("RCSMER.INP","r",stdin);
    freopen("RCSMER.OUT","w",stdout);
    cin >> s1 >> s2;
    tinh(s1,s2,0,0,"");
    cout << MIN << endl << MAX;
    return 0;
}
