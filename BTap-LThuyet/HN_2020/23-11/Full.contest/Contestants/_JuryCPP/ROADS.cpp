#define taskname "ROADS"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int maxN = 1e5 + 1;
const int maxM = 1e5 + 1;
struct TEdge;
using PEdge = TEdge*;
struct TEdge
{
    int u, v, c;
    PEdge trace;
};
TEdge e[2 * maxM];
vector<PEdge> adj[maxN];
int vcolor[maxN];
int n, m, s, t;
queue<PEdge> Q;
PEdge FirstEdge;

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void ReadInput()
{
    n = ReadInt();
    m = ReadInt();
    s = ReadInt();
    t = ReadInt();
    int j = 0;
    for (int i = 0; i < m; ++i)
    {
        int x = ReadInt();
        int y = ReadInt();
        int c = ReadInt();
        e[j++] = {x, y, c, nullptr};
        e[j++] = {y, x, c, nullptr};
    }
}

void Init()
{
    for (int i = 0; i < 2 * m; ++i)
        adj[e[i].u].push_back(&e[i]);
    fill(vcolor + 1, vcolor + n + 1, -1);
}

PEdge BFS()
{
    for (PEdge e: adj[t])
    {
        if (e->v == s) return e;
        Q.push(e);
    }
    adj[t].clear();
    while (!Q.empty())
    {
        PEdge uEdge = Q.front(); Q.pop();
        int x = uEdge->v;
        if (uEdge->c == vcolor[x]) continue;
        vcolor[x] = uEdge->c;
        for (int i = (int)adj[x].size() - 1; i >= 0; --i)
        {
            PEdge& vEdge = adj[x][i];
            if (vEdge->c == uEdge->c) continue;
            vEdge->trace = uEdge;
            if (vEdge->v == s) return vEdge;
            Q.push(vEdge);
            vEdge = adj[x].back();
            adj[x].pop_back();
        }
    }
    return nullptr;
}

void Print()
{
    if (FirstEdge == nullptr)
    {
        putchar('-'); putchar('1');
        return;
    }
    vector<int> res;
    for (PEdge ep = FirstEdge; ep != nullptr; ep = ep->trace)
    {
        int i = ep - e;
        res.push_back(i / 2 + 1);
    }
    WriteInt(res.size());
    putchar('\n');
    for (int i: res)
    {
        WriteInt(i);
        putchar(' ');
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Init();
    FirstEdge = BFS();
    Print();
}
