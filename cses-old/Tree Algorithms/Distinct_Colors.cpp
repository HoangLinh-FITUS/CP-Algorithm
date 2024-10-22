#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int N = 2e5 + 1;

int n;
vector <int> a[N];
int c[N];
set <int> s[N];
int res[N];

void dfs(int u,int p) {
    s[u].insert(c[u]);
    for(auto v : a[u]) if (v != p) {
        dfs(v,u);
        if (s[u].size() < s[v].size()) swap(s[u],s[v]);
        for(auto z: s[v]) s[u].insert(z);
    }
    res[u] = s[u].size();
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}