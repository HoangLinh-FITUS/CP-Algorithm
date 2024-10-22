#include <iostream>
#define DB(x) cerr << #x << " = " << x << '\n';

using namespace std;
const int N = 101;

typedef int Array2d[N][N];

Array2d len,trace;
int res[N];
int n,m,k;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        trace[i][i] = i;
        for(int j = 1; j <= n; j++) if (i != j) len[i][j] = 1e9;
    }

    while (m--) {
        int u,v,c;
        cin >> u >> v >> c;
        len[u][v] = len[v][u] = c;
        trace[u][v] = v;
        trace[v][u] = u;
    }

    for(int tmp = 1; tmp <= n; tmp++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (len[i][j] > len[i][tmp] + len[tmp][j]) {
                    len[i][j] = len[i][tmp] + len[tmp][j];
                    trace[i][j] = trace[i][tmp];
                }
            }
        }
    }
    while (k--) {
        int u,v;
        bool type;
        cin >> type >> u >> v;
        if (!type) cout << len[u][v] << '\n';
        else {
            res[0] = 0;
            while (v != u) {
                res[++res[0]] = u;
                u = trace[u][v];
            }
            res[++res[0]] = u;
            cout << res[0] << " ";
            for(int i = 1; i <= res[0]; i++) cout << res[i] << " ";cout << '\n';
        }
    }
    return 0;
}