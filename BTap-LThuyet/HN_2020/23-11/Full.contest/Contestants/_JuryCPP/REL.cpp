#define taskname "REL"
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
const int maxN = 1e3;
int n, nscc;
int a[maxN][maxN], b[maxN][maxN];
int lab[maxN], d[maxN], low[maxN], num[maxN];

stack<int> Stack;

inline void Minimize(int& Target, int Val)
{
    if (Target > Val) Target = Val;
}

inline void Maximize(int& Target, int Val)
{
    if (Target < Val) Target = Val;
}

void Enter()
{
    fill_n(&a[0][0], sizeof(a) / sizeof(a[0][0]), -1);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int r;
            cin >> r;
            switch (r)
            {
                case 0: Maximize(a[i][j], 0); Maximize(a[j][i], 0); break;
                case 1: Maximize(a[j][i], 1); break;
                case -1: Maximize(a[i][j], 1); break;
                case 2: Maximize(a[j][i], 0); break;
                case -2: Maximize(a[i][j], 0); break;
            }
        }
}

void Visit(int u)
{
    static int Cnt = 0;
    num[u] = Cnt++;
    low[u] = maxN + 1;
    Stack.push(u);
    for (int v = 0; v < n; ++v)
    {
        if (lab[v] != -1 || a[u][v] < 0) continue;
        if (num[v] != -1) Minimize(low[u], num[v]);
        else
        {
            Visit(v);
            Minimize(low[u], low[v]);
        }
    }
    if (low[u] >= num[u])
    {
        while (true)
        {
            int v = Stack.top(); Stack.pop();
            lab[v] = nscc;
            if (v == u) break;
        }
        ++nscc;
    }
}

void FindSCC()
{
    fill(begin(lab), end(lab), -1);
    fill(begin(num), end(num), -1);
    nscc = 0;
    for (int s = 0; s < n; ++s)
        if (num[s] == -1) Visit(s);
    fill_n(&b[0][0], sizeof(b) / sizeof(b[0][0]), -1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] < 0) continue;
            Maximize(b[lab[i]][lab[j]], a[i][j]);
        }
}

void Solve()
{
    fill_n(&d[0], nscc, 1);
    for (int u = nscc - 1; u >= 0; --u)
        for (int v = 0; v < nscc; ++v)
            if (b[u][v] >= 0)
                Maximize(d[v], d[u] + b[u][v]);
    for (int i = 0; i < n; ++i)
        cout << d[lab[i]] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    FindSCC();
    Solve();
}
