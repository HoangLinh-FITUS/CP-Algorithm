#include <iostream>
#include <vector>

using namespace std;
const int N = 2501;

int n,m;
vector <pair<pair<int,int>,int>> e;
long long dp[N];
int trace[N],dd[N];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        e.push_back({{u,v},w});
    }

    int cycle = 0;
    for(int i = 1; i <= n; i++) {
        bool ok = 0;
        for(auto j: e) {
            int u = j.first.first;
            int v = j.first.second;
            int w = j.second;
            if (dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
                trace[v] = u;
                ok = 1;
            }
        }
        cycle += ok;
    }
    if (cycle != n) cout << "NO";
    else {
        cout << "YES\n";
        for(int i = 1; i <= n; i++) if (!dd[i]) {
            int x = i;
            vector <int> res; 
            vector <int> cancel;
            while (x > 0) {
                cancel.push_back(x);
                if (dd[x] == 1) {
                    int y = trace[x];
                    res.push_back(x);
                    while (x != y) {
                        res.push_back(y);
                        y = trace[y];
                    }
                    res.push_back(x);
                    for(auto it = res.rbegin(); it != res.rend(); it++) cout << *it << " ";
                    return 0;
                }
                dd[x] = 1;
                x = trace[x];
            }
            for(auto j : cancel) dd[j] = 2;
        }
    }
    return 0;
}