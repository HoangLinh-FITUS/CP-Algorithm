#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 1;

vector <int> a[N];
int n,res = 0;
int dd[N];

void dfs(int u,int p) {
    for(auto v : a[u]) if (v != p) {
        dfs(v,u);
        if (!dd[u] && !dd[v]) {
            dd[u] = dd[v] = 1;
            res++;
        }
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
    cout << res;
    return 0;
}