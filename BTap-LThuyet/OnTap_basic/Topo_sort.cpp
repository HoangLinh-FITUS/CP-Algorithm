#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 1;

int n,m;
vector <int> Graph[N],topo;
vector <pair<int,int>> e;
int dd[N];

void dfs(int u) {
    dd[u] = 1;
    for(auto v : Graph[u]) if (!dd[v]) dfs(v);
    topo.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        Graph[u].push_back(v);
        e.push_back({u,v});
    }
    for(int i = 1; i <= n; i++) if (!dd[i]) dfs(i);
    reverse(topo.begin(),topo.end());
    int *C = new int[n + 1];
    C[0] = 0;
    for(auto i : topo) C[i] = ++C[0];
    for(auto i : e) if (C[i.first] > C[i.second]) return cout << "IMPOSSIBLE",0;
    for(auto i : topo) cout << i << " ";
    return 0;
}