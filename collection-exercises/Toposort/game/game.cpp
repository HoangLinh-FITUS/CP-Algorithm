#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
const int N = 1e5 + 1;
 
int n,m;
vector <int> graph[N],topo;
int dd[N],trace[N],dp[N];
 
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
    dp[1] = 1;
    for(int i = 0; i < n; i++) {
        int u = topo[i];
        for(auto v: graph[u]) {
            dp[v] += dp[u];
            dp[v] %= (int)1e9 + 7;
        }
    } 
    cout << dp[n];
    return 0;
}