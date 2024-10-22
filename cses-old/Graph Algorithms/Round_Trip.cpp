#include <vector>
#include <iostream>

using namespace std;
const int N = 1e5 + 1;

vector <int> graph[N];
int n,m;
int dd[N],trace[N];

void dfs(int u,int p = -1) {
    if (dd[u] == 1) {
        vector <int> res;
        res.push_back(u);
        for(; p != u; p = trace[p]) res.push_back(p);
        res.push_back(u);
        cout << res.size() << '\n';
        for(auto i : res) cout << i << " ";
        exit(0);
    }   
    dd[u] = 1;
    for(auto v: graph[u]) if (v != p && dd[v] != 2) {
        trace[v] = u;
        dfs(v,u);
    }
    dd[u] = 2;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) if (!dd[i]) dfs(i);
    cout << "IMPOSSIBLE";
    return 0;
}