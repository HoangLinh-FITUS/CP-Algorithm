#include <bits/stdc++.h>

#define task "PRODUCT"
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
const int N = 1e5 + 2, mod = 123456789;
int n, T, K, a[N], suf[N];
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> K;
        int num0 = 0, du = 0, am = 0;
        rep(i, 1, n) cin >> a[i], num0 += (a[i] == 0), du += (a[i] > 0);
        am = n - num0 - du;
        if (n - K < num0)
        {
            cout << "0\n";
            continue;
        }
        if (num0 && du == 0 && (K & 1))
        {
            cout << "0\n";
            continue;
        }
        sort(a + 1, a + 1 + n);
        if (du == 0 && (K & 1))
        {
            ll pro = 1;
            Rep(i, n, n - K + 1) pro = (pro * (-a[i])) % mod;
            cout << (mod - pro) << '\n';
            continue;
        }
        int ans = 1;
        int i = 1, j = n;
        if (am / 2 * 2 + du < K)
        {
            if (num0)
            {
                cout << "0\n";
                continue;
            } else
            {
                ll pro = 1;
                rep(i, 1, n) pro = (pro * abs(a[i])) % mod;
                cout << (mod - pro) << '\n';
            }
        } else
        {
            if (K % 2 == 0) rep(I, 1, K / 2)
            {
                if (i + 1 > am) ans = ans * 1LL * (a[j] * 1LL * a[j - 1] % mod) % mod, j -= 2;
                else if (n - j + 2 > du) ans = ans * 1LL * (a[i] * 1LL * a[i + 1] % mod) % mod, i += 2;
                else if ((a[j] * 1LL * a[j - 1]) < (a[i] * 1LL * a[i + 1])) ans = ans * 1LL * (a[i] * 1LL * a[i + 1] % mod) % mod, i += 2;
                else ans = ans * 1LL * (a[j] * 1LL * a[j - 1] % mod) % mod, j -= 2;
            } else
            {
                ans = a[n];
                j--;
                rep(I, 1, K / 2)
                {
                    if (i + 1 > am) ans = ans * 1LL * (a[j] * 1LL * a[j - 1] % mod) % mod, j -= 2;
                    else if (n - j + 2 > du) ans = ans * 1LL * (a[i] * 1LL * a[i + 1] % mod) % mod, i += 2;
                    else if ((a[j] * 1LL * a[j - 1]) < (a[i] * 1LL * a[i + 1])) ans = ans * 1LL * (a[i] * 1LL * a[i + 1] % mod) % mod, i += 2;
                    else ans = ans * 1LL * (a[j] * 1LL * a[j - 1] % mod) % mod, j -= 2;
                }
            }
            cout << ans << '\n';
        }

    }
    return 0;
}
