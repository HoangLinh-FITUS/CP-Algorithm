#include <iostream>
#include <vector>
#include <queue>

#define int long long 

using namespace std;
using ii = pair<int,int>;

const int N = 1e5 + 1,mod = 1e9 + 7;

int n,m;
vector <pair<int,int>> adj[N];
int dist[N],way[N],Max[N],Min[N];

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e18;
        way[i] = 0;
        Max[i] = 0;
        Min[i] = n;
    }
    priority_queue <ii,vector<ii>,greater<ii>> q;
    q.push({0,1});
    dist[1] = 0;
    way[1] = 1;
    Max[1] = 0;
    Min[1] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (du != dist[u]) continue;
        for(auto i: adj[u]) {
            int v = i.first;
            int w = i.second;
            if (dist[v] > du + w) {
                dist[v] = du + w;
                Max[v] = Max[u] + 1;
                Min[v] = Min[u] + 1;
                way[v] = way[u];
                q.push({dist[v],v});
            } else if (dist[v] == du + w) {
                Max[v] = max(Max[v],Max[u] + 1);
                Min[v] = min(Min[v],Min[u] + 1);
                way[v] += way[u];
                way[v] %= mod;
            }
        }
    }
    cout << dist[n] << " " << way[n] << " " << Min[n] << " " << Max[n];

    return 0;
}