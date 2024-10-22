#include <iostream>
#include <vector>

using namespace std;
const int N = 801;

int n,m;
vector <int> G[N];
bool dd[N];
vector <int> Path;

void topo(int u) {
    dd[u] = 1;
    for(auto v : G[u]) if (!dd[v]) topo(v);
    Path.push_back(u);
}

void dfs(int u) {
    dd[u] = 1;
    for(auto v : G[u]) if (!dd[v]) dfs(v);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) if (!dd[i]) topo(i);
    for(int i = 1; i <= n; i++) dd[i] = 0;
    int cnt = 0;
    for(auto it = Path.rbegin(); it != Path.rend(); it++) {
        if (!dd[*it]) dfs(*it),cnt++;
    }
    cout << cnt;
    return 0;
}