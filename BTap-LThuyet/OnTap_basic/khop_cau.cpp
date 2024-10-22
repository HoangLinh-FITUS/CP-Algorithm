#include <iostream>
#include <vector>

using namespace std;
constexpr int N = 1e4 + 1;

vector <int> Graph[N];
int n,m;
int num[N],low[N],khop[N],child[N];
int cau = 0;

void dfs(int u,int p) {
    num[u] = low[u] = ++num[0];
    for(auto v : Graph[u]) {
        if (v == p) continue;
        if (!num[v]) {
            child[u]++;
            dfs(v,u);
            if (low[v] > num[u]) cau++;
            if (low[v] >= num[u]) khop[u] = 1;
            low[u] = min(low[u],low[v]);
        } else low[u] = min(low[u],num[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) if (!num[i]) {
        dfs(i,i);
        khop[i] = child[i] > 1;
    }
    int cnt_khop = 0;
    for(int i = 1; i <= n; i++) cnt_khop += khop[i];
    cout << cnt_khop << " " << cau;
    return 0;
}