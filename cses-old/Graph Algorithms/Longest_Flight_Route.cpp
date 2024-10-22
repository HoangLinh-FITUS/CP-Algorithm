#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 1;

int n,m;
vector <int> graph[N],topo;
int dd[N],trace[N];
long long dp[N];

void dfs(int u) {
    dd[u] = 1;
    for(auto v: graph[u]) if (!dd[v]) dfs(v);
    topo.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) if (!dd[i]) dfs(i);
    reverse(topo.begin(),topo.end());
    for(int i = 2; i <= n; i++) dp[i] = -1e18;
    for(int i = 0; i < n; i++) {
        int u = topo[i];
        for(auto v: graph[u]) {
            if (dp[v] < dp[u] + 1) {
                trace[v] = u;
                dp[v] = dp[u] + 1;
            }
        }
    } 
    if (dp[n] == -1e18) return cout << "IMPOSSIBLE",0;
    cout << dp[n] + 1 << '\n';
    vector <int> res;
    while (n) {
        res.push_back(n);
        n = trace[n];
    }
    reverse(res.begin(),res.end());
    for(auto i: res) cout << i << " ";
    return 0;
}