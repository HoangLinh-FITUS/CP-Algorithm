#include <bits/stdc++.h>

#define task "TASKSELECT"
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (int i = (r); i >= (l); --i)
#define DB(X) { cerr << #X << " = " << (X) << '\n'; }
#define DB1(A, _) { cerr << #A << "[" << _ << "] = " << (A[_]) << '\n'; }
#define DB2(A, _, __) { cerr << #A << "[" << _ << "][" << __ << "] = " << (A[_][__]) << '\n'; }
#define DB3(A, _, __, ___) { cerr << #A << "[" << _ << "][" << __ << "][" << ___ << "] = " << (A[_][__][___]) << '\n'; }
#define PR(A, l, r) { cerr << '\n'; rep(_, l, r) DB1(A, _); cerr << '\n';}
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define pf push_front
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define next ___next
#define prev ___prev
#define y1 ___y1
#define left ___left
#define right ___right
#define y0 ___y0
#define div ___div
#define j0 ___j0
#define jn ___jn

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<vi> vvi;
const int mod = 1e9 + 7;
struct Matrix
{
    int r, c;
    vvi mat;
    Matrix(vvi val) : r(SZ(val)), c(SZ(val[0])), mat(val) {}
    static Matrix iden(int r)
    {
        vvi res(r, vi(r, 0));
        rep(i, 0, r - 1) res[i][i] = 1;
        return Matrix(res);
    }
    Matrix operator * (const Matrix &oth)
    {
        vvi res(r, vi(oth.c, 0));
        assert(c == oth.r);
        rep(i, 0, r - 1) rep(j, 0, oth.c - 1) rep(k, 0, c - 1)
            (res[i][j] += mat[i][k] * 1LL * oth.mat[k][j] % mod) %= mod;
        return Matrix(res);
    }
};
Matrix fpow(Matrix &x, int y)
{
    Matrix res = Matrix::iden(x.r);
    while (y)
    {
        if (y & 1) res = res * x;
        y >>= 1;
        x = x * x;
    }
    return res;
}
int n, K, T;
void solve()
{
    cin >> K >> n;
    int nn = K;
    vvi A(K * K + 1, vi(K * K + 1));
    A[0][1] = 1;
    rep(i, 1, K)
    {
        int lst = i;
        rep(j, 1, i - 1)
        {
            A[lst][++nn] = 1;
            lst = nn;
        }
        A[lst][i] = 1;
        if (i < K)
        {
            lst = i;
            rep(j, 1, i)
            {
                A[lst][++nn] = 1;
                lst = nn;
            }
            A[lst][i + 1] = 1;
        }
    }
    assert(nn == K * K);
    Matrix Base(A);
    Base = fpow(Base, n);
    cout << Base.mat[0][K] << '\n';
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) solve();
    return 0;
}
