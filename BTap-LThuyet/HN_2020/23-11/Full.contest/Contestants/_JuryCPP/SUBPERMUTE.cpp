#define taskname "SUBPERMUTE"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 1e5;
const int maxK = 1e5;

int n, k;
int a[maxN + 1];
int lastpos[maxK + 1];
bool b[maxK + 1];

void ReadInput()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void Init()
{
    fill(lastpos + 1, lastpos + k + 1, 0);
    for (int i = n; i > 0; --i)
    {
        int x = a[i];
        if (lastpos[x] == 0) lastpos[x] = i;
    }
}

void Solve()
{
    fill(b + 1, b + k + 1, true);
    vector<int> s;
    for (int i = 1; i <= n; ++i)
    {
        if (!b[a[i]]) continue;
        while (!s.empty() && s.back() >= a[i] && lastpos[s.back()] >= i)
        {
            b[s.back()] = true;
            s.pop_back();
        }
        s.push_back(a[i]);
        b[a[i]] = false;
    }

    for (int x: s)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    int ntests;
    for (cin >> ntests; ntests > 0; --ntests)
    {
        ReadInput();
        Init();
        Solve();
    }
}
