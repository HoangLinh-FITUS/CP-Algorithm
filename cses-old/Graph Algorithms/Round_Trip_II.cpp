#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 1;

vector <int> adj[N];
int n,m;
int dd[N],trace[N];

void dfs(int u) {
    if (dd[u] == 1) {
        vector <int> res;
        res.push_back(u);
        for(int x = trace[u]; x != u; x = trace[x]) res.push_back(x);
        res.push_back(u);
        cout << res.size() << '\n';
        for(auto i = res.rbegin(); i != res.rend(); i++) cout << *i << " ";
        exit(0);
    }
    dd[u] = 1;
    for(auto v: adj[u]) if (dd[v] != 2){
        trace[v] = u;
        dfs(v);
    }
    dd[u] = 2;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) if (!dd[i]) dfs(i);
    cout << "IMPOSSIBLE";
    return 0;
}