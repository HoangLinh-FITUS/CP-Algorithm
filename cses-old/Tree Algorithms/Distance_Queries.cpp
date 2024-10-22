#include <iostream>
#include <vector>

using namespace std;
const int N = 2e5 + 1;

int n,q;
int up[N][20];
vector <int> a[N];
int deep[N];

void dfs(int u,int p) {
    up[u][0] = p;
    for(int i = 1; i < 20; i++) up[u][i] = up[up[u][i - 1]][i - 1];
    for(auto v : a[u]) if (v != p) {
        deep[v] = deep[u] + 1;
        dfs(v,u);
    }
}

int get(int u,int v) {
    if (deep[u] > deep[v]) swap(u,v);
    for(int i = 19; i >= 0; i--) if ((1 << i) <= deep[v] - deep[u]) v = up[v][i];
    if (u == v) return u;
    for(int i = 19; i >= 0; i--) if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
    }
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1,0);

    while (q--) {
        int u,v;
        cin >> u >> v;
        cout << deep[v] + deep[u] - 2 * deep[get(u,v)] << '\n';
    }
    return 0;
}