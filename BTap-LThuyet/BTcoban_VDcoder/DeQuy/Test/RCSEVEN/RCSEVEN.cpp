#include <bits/stdc++.h>
using namespace std;
long long so(char st)
{
    return int(st)-48;
}
long long chan(string xau,long long dem)
{
    if (xau.size() == 0)
    {
        return dem;
    }
    return (so(xau[0]) % 2 == 0)? chan(xau.erase(0,1),dem + so(xau[0])):chan(xau.erase(0,1),dem);
}
int main()
{
	freopen("RCSEVEN.INP","r",stdin);
	freopen("RCSEVEN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string xau;
    cin >> xau;
    cout << chan(xau,0);
    return 0;
}
    