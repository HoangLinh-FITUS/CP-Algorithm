#include <bits/stdc++.h>
using namespace std;
long long l,n, k = 0;
map < char,long long> m;
void chuyen(long long n,char a,char b,char c)
{
    if (n == 1)
    {
        k++;
        if (a == 'A')
            m['A']--;
        if (a == 'B')
            m['B']--;
        if (a == 'C')
            m['C']--;
        if (b == 'A')
            m['A']++;
        if (b == 'B')
            m['B']++;
        if (b == 'C')
            m['C']++;
        if (k == l)
        {
           cout << m['A'] << " " << m['B'] << " " << m['C'];
           exit(0);
        }
    }
    else
     {
         chuyen(n-1,a,c,b);
         chuyen(1,a,b,c);
         chuyen(n-1,c,b,a);
     }
}
int main()
{
    freopen("HANOI.INP","r",stdin);
    freopen("HANOI.OUT","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> l;
    m['A'] = n;m['B'] = 0;m['C'] = 0;
    chuyen(n,'A','B','C');
    return 0;
}