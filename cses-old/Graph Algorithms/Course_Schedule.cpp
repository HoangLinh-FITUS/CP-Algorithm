#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 1;

int n,m;
vector <int> graph[N];
vector <int> topo;
int dd[N];

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
    dd[0] = 0;
    for(auto i: topo) dd[i] = ++dd[0];
    for(auto i: topo) {
        for(auto j: graph[i]) if (dd[j] < dd[i]) return cout << "IMPOSSIBLE",0;  
    }
    for(auto i: topo) cout << i << " ";
    return 0;
}