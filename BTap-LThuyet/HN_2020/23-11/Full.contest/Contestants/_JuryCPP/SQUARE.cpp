#define taskname "SQUARE"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxN = 1e5;
const int infty = 2e9;
int n;
struct TPoint
{
    int x, y;
} p[maxN];
int f[maxN];

inline int ReadInt()
{
    bool neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-')
            neg = !neg;
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return neg ? -x : x;
}

void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}

inline void Maximize(int& Target, int Value)
{
    if (Target < Value)
        Target = Value;
}

inline void Minimize(int& Target, int Value)
{
    if (Target > Value)
        Target = Value;
}

void ReadInput()
{
    n = ReadInt();
    for (int i = 0; i < n; ++i)
    {
        p[i].x = ReadInt();
        p[i].y = ReadInt();
    }
}

int FindD()
{
    TPoint A, B;
    A = p[0], B = p[0];
    for (int i = 1; i < n; ++i)
    {
        Minimize(A.x, p[i].x);
        Minimize(A.y, p[i].y);
        Maximize(B.x, p[i].x);
        Maximize(B.y, p[i].y);
    }
    int res = 1;
    for (int i = 0; i < n; ++i)
    {
        int d1 = max(p[i].x - A.x, p[i].y - A.y);
        int d2 = max(B.x - p[i].x, B.y - p[i].y);
        Maximize(res, min(d1, d2));
    }
    return res;
}

void Solve1()
{
    int d1 = FindD();
    for (int i = 0; i < n; ++i)
        p[i].x = -p[i].x;
    int d2 = FindD();
    WriteInt(min(d1, d2));
}

int FindK()
{
    sort(p, p + n, [](const TPoint& p, const TPoint& q)
    {
        return p.x < q.x;
    });
    int minY, maxY;
    minY = infty; maxY = -infty;
    int L = p[0].x;
    for (int i = 0; i < n; ++i)
    {
        Minimize(minY, p[i].y);
        Maximize(maxY, p[i].y);
        f[i] = max(maxY - minY, p[i].x - L);
    }
    minY = infty; maxY = -infty;
    int R = p[n - 1].x;
    int res = f[n - 1];
    for (int i = n - 1; i > 0; --i)
    {
        Minimize(minY, p[i].y);
        Maximize(maxY, p[i].y);
        if (p[i].x != p[i - 1].x)
        {
            int d2 = max(maxY - minY, R - p[i].x);
            Minimize(res, max(f[i - 1], d2));
        }
    }
    return res == 0 ? 1 : res;
}

void Solve2()
{
    int k1 = FindK();
    for (int i = 0; i < n; ++i)
        swap(p[i].x, p[i].y);
    int k2 = FindK();
    WriteInt(min(k1, k2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    int C = ReadInt();
    while (C-- > 0)
    {
        ReadInput();
        Solve1();
        putchar(' ');
        Solve2();
        putchar('\n');
    }
}
