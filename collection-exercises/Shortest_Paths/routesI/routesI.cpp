#include <iostream>
#include <queue>
 
#define int long long 
#define ii pair<int,int>
 
using namespace std;
 
const int N = 1e5 + 1;
 
vector <ii> G[N];
int n,m;
 
void dij(int s,int *dist) {
    priority_queue <ii,vector<ii>,greater<ii>> q;
    for(int i = 1; i <= n; i++) dist[i] = 1e18;
    q.push({0,s});
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (dist[u] != du) continue;
        for(auto i : G[u]) {
            int v = i.first;
            int w = i.second;
            if (dist[v] > du + w) {
                dist[v] = du + w;
                q.push({dist[v],v});
            }
        }
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    int *dist = new int[n + 1];
    dij(1,dist);
    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    return 0;
}