#define taskname "TASKSELECT"
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
using lli = long long;
const int maxK = 10;
const int MOD = 1e9 + 7;
using TMatrix = vector<vector<int>>;

int k, n, s;
vector<pair<int, int>> e;
TMatrix A, B, temp;

void AddLine(int u, int v, int w)
{
    for (int i = 1; i < w; ++i)
    {
        ++s;
        e.emplace_back(u, s);
        u = s;
    }
    e.emplace_back(u, v);
}

void InitZeroMatrix(TMatrix& a)
{
    a.resize(s + 1);
    for (vector<int>& line: a)
    {
        line.resize(s + 1);
        fill(line.begin(), line.end(), 0);
    }
}

void Init()
{
    s = k;
    e.clear();
    for (int i = 1; i <= k; ++i)
    {
        AddLine(i - 1, i, i);
        AddLine(i, i, i);
    }
    InitZeroMatrix(A);
    for (const pair<int, int>& p: e)
        A[p.first][p.second] = 1;
    InitZeroMatrix(B);
    for (int i = 0; i <= s; ++i)
        B[i][i] = 1;
    InitZeroMatrix(temp);
}

void MulMat(const TMatrix& A, const TMatrix& B, TMatrix& C)
{
    for (int x = 0; x <= s; ++x)
        for (int y = 0; y <= s; ++y)
        {
            int& q = temp[x][y];
            q = 0;
            for (int z = 0; z <= s; ++z)
                q = (q + lli(A[x][z]) * B[z][y]) % MOD;
        }
    swap(C, temp);
}

void Solve()
{
    for (; n > 0; n /= 2)
    {
        if (n % 2 == 1) MulMat(B, A, B);
        MulMat(A, A, A);
    }
    cout << B[0][k] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    int ntests;
    cin >> ntests;
    while (ntests-- > 0)
    {
        cin >> k >> n;
        Init();
        Solve();
    }
}

