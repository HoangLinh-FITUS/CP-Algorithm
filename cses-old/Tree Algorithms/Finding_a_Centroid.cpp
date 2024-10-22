#include <iostream>
#include <vector>

using namespace std;
const int N = 2e5 + 1;

int n;
vector <int> a[N];
int Size[N];

int dfs(int u,int p) {
    Size[u] = 1;
    for(int v: a[u]) if (v != p) Size[u] += dfs(v,u);
    return Size[u];
}

int centroid(int u,int p) {
    for(int v: a[u]) if (v != p && Size[v] > n / 2) return centroid(v,u);
    return u;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    cout << centroid(1,0) << '\n';
    return 0;
}