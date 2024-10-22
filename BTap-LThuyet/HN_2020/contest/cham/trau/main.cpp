#include <bits/stdc++.h>

#define For(_i,_a,_b) for (int _i=_a; _i<=_b; _i++)
#define Ford(_i,_a,_b) for (int _i=_a; _i>=_b; _i--)

#define x first
#define y second

#define pb push_back
#define ALL(vecS) vecS.begin(),vecS.end()

#define task "riceatm"

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> lli;
typedef vector <int> vi;
typedef pair <int, ll> ill;

const int N = 2e5 + 3;
const ll MOD = 1e9 + 7;
const ll oo = 1e18;

int n;
ll a[N], b[N], dp[N][5];

void Trace(int i, int st)
{
    if (i == n + 1) return;
    cout << st << " ";
    if (st == 0)
        {
            if (dp[i + 1][1] <= dp[i + 1][2]) Trace(i + 1, 1);
                    else Trace(i + 1, 2);
        }
    if (st == 1)
    {
        if (dp[i + 1][1] <= dp[i + 1][2]) Trace(i + 1, 1);
        else Trace(i + 1, 2);
    }
    if (st == 2)
    {
        Trace(i + 1, 0);
    }
}

int main()
{
    ifstream(task".inp");
    ofstream(task".ans");

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    For(i, 1, n) cin >> a[i] >> b[i];
    //dp[n + 1][1] = dp[n + 1][2] = 1e13;
    Ford(i, n, 1)
    {
        dp[i][0] = min(dp[i + 1][1], dp[i + 1][2]);
        dp[i][1] = min(dp[i + 1][1], dp[i + 1][2]) + a[i];
        dp[i][2] = dp[i + 1][0] + b[i];
    }

    cout << min(dp[1][1], dp[1][2]) << '\n';
    if (dp[1][1] <= dp[1][2]) Trace(1, 1); else Trace(1, 2);
    return 0;
}
