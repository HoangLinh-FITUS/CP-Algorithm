#include <iostream>
#include <vector>

using namespace std;
const int N = 2501;

int n,m;
vector <pair<pair<int,int>,int>> e;
long long dp[N];
bool vis1[N],vis2[N];
vector <int> adj1[N],adj2[N];

void dfs(int u,bool *vis,vector <int> *adj) {
    vis[u] = 1;
    for(auto v: adj[u]) if (!vis[v]) dfs(v,vis,adj);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,w,v;
        cin >> u >> v >> w;
        e.push_back({{u,v},w});
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    dfs(1,vis1,adj1);
    dfs(n,vis2,adj2);

    for(int i = 2; i <= n; i++) dp[i] = -1e18;
    for(int i = 1; i <= 2 * n; i++) {
        for(auto x: e) {
            int u = x.first.first;
            int v = x.first.second;
            int w = x.second;
            if (dp[v] < dp[u] + w) {
                dp[v] = dp[u] + w;
                if (i > n && vis1[v] && vis2[v]) return cout << -1,0; 
            }
        } 
    }
    cout << dp[n];
    return 0;
}