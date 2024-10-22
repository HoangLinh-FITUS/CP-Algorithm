#include <bits/stdc++.h>
using namespace std;
long long so(char st)
{
    return int(st)-48;
}
long long MAX(string xau,long long M)
{
    if (xau.size() == 0)
    {
        return M;
    }
    return MAX(xau.erase(0,1),max(so(xau[0]),M));
}
int main()
{
	freopen("RCSMAXNU.INP","r",stdin);
	freopen("RCSMAXNU.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string xau;
    cin >> xau;
    cout << MAX(xau,-1);
    return 0;
}
    