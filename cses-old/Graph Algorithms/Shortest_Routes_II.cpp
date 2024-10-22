#include <iostream>
#include <queue>
 
#define int long long 
#define ii pair<int,int>
 
using namespace std;
 
const int N = 5e2 + 1;

int n,m;
int dist[N][N];

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) 
    for(int j = i + 1; j <= n; j++) dist[i][j] = dist[j][i] = 1e18;
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v],w);
        dist[v][u] = dist[u][v];
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }    

    while (q--) {   
        int u,v;
        cin >> u >> v;
        if (dist[u][v] == 1e18) cout << "-1\n";
        else cout << dist[u][v] << '\n';
    }
    return 0;
}
