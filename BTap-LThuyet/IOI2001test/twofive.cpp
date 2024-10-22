#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define REPD( i, n ) for ( i = (n) - 1; i >= 0; i--)
#define se second
#define fi first
#define fileinp freopen("twofive.in","r",stdin)
#define fileout freopen("twofive.out","w",stdout)
#define ll long long

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,tree_tag,tree_order_statistics_node_update> Tree;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll MAXL = 26;

ll N;
char W[MAXL];
ll dp[6][6][6][6][6];
ll s[6];
ll x[MAXL];
ll y[MAXL];
bool used[MAXL];

int count() {

    memset( dp, 0, sizeof( dp ) );
    dp[5][5][5][5][5] = 1;

    s[0] = 5;
    REPD( s[1], 6 )
    REPD( s[2], 6 )
    REPD( s[3], 6 )
    REPD( s[4], 6 )
    REPD( s[5], 6 ) {

        ll ch = s[1]+s[2]+s[3]+s[4]+s[5];
        ll &val = dp[s[1]][s[2]][s[3]][s[4]][s[5]];

        if ( used[ch] ) {
            if ( s[ x[ch] ] < s[ x[ch] - 1 ] && s[ x[ch] ] + 1 == y[ch] ) {
                s[ x[ch] ]++;
                val = dp[s[1]][s[2]][s[3]][s[4]][s[5]];
                s[ x[ch] ]--;
            }
        } else
            for ( int i = 1; i <= 5; i++ )
                if ( s[i] < s[i - 1] ) {
                    s[i]++;
                    val += dp[s[1]][s[2]][s[3]][s[4]][s[5]];
                    s[i]--;
                }
    }

    return dp[0][0][0][0][0];
}

int main() {
    fileinp;
    fileout;
    if ( getchar() == 'W' ) {
        cin >> W;
        fu(i,1,5) fu(j,1,5) fu(k,0,24)
        {
            if ( used[k] ) continue;
            used[k] = true;
            x[k] = i;
            y[k] = j;
            if ( W[(i-1)*5+j-1] == k + 'A' )
                break;
            N += count();
            used[k] = false;
        }

        cout << N + 1 << '\n';

    } else {

        cin >> N;
        N--;
        fu(i,1,5) fu(j,1,5) fu(k,0,24)
        {
            if ( used[k] ) continue;
            used[k] = true;
            x[k] = i;
            y[k] = j;
            ll cnt = count();
            if ( cnt > N ) {
                W[(i-1)*5+j-1] = k + 'A';
                break;
            }
            N -= cnt;
            used[k] = false;
        }

        cout << W << '\n';
    }
}
