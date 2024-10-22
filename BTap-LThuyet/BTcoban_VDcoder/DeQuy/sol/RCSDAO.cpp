#include <bits/stdc++.h>
using namespace std;
string dao(string st)
{
    if (st.size() == 1)
    {
        return st;
    }
    return dao(st.erase(0,1)) + st[0];
}
int main()
{
	freopen("RCSDAO.INP","r",stdin);
	freopen("RCSDAO.OUT","w",stdout);
    string xau;
    getline(cin,xau);
    cout << dao(xau);
    return 0;
}
    