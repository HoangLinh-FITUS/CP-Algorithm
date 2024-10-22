#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 1;

vector <int> a[N];
int n,res = 0;
int d[N];

void dfs(int u,int p) {
    for(auto v : a[u]) if (v != p) {
        d[v] = d[u] + 1;
        dfs(v,u);
    }
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
    int S = 0;
    for(int i = 1; i <= n; i++) if (d[S] < d[i]) S = i;
    for(int i = 1; i <= n; i++) d[i] = 0;
    dfs(S,0);
    int T = 0;
    for(int i = 1; i <= n; i++) if (d[T] < d[i]) T = i;

    int *res = new int[n + 1];
    for(int i = 1; i <= n; i++) d[i] = 0;
    dfs(S,0);
    for(int i = 1; i <= n; i++) res[i] = d[i];

    for(int i = 1; i <= n; i++) d[i] = 0;
    dfs(T,0);
    for(int i = 1; i <= n; i++) res[i] = max(res[i],d[i]);
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}