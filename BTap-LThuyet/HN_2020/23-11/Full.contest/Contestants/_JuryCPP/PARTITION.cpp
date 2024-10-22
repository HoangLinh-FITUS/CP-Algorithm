#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
typedef long long lli;

struct lf
{
    inline bool operator()(int x, int y)
    {
        return y < x;
    }
};

priority_queue<int, vector<int>, lf> pq;
int n, L;

void Enter()
{
    cin >> L >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
        L -= a;
    }
    if (L > 0) pq.push(L);
}

void Solve()
{
    lli res = 0;
    while (pq.size() > 1)
    {
        int u = pq.top(); pq.pop();
        int v = pq.top(); pq.pop();
        res += u + v;
        pq.push(u + v);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("PARTITION.inp", "r", stdin);
    freopen("PARTITION.out", "w", stdout);

    Enter();
    Solve();
}
