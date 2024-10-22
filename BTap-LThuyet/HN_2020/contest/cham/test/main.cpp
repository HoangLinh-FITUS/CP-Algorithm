#include <bits/stdc++.h>
using namespace std;
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int a[100001];
int n,m;
const int mod = 1000;

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp("RICEATM.inp");
        n = rand()%mod + 1;
        inp << n << '\n';
        for(int i = 1; i <= 2*n; i++)
        {
            int x;
            x = rand()%mod + 1;
            inp << x << " ";
        }
        inp << '\n';
        inp.close();
        system("RICEATM.exe");
        system("trau.exe");
        if(system("fc RICEATM.out RICEATM.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        else
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
