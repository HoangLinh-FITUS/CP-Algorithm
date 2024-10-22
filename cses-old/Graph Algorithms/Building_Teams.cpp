#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 1;

int n,m;
vector <int> graph[N];
int dd[N],res[N];

void bfs(int s) {
    queue <int> q;
    q.push(s);
    res[s] = 0;
    dd[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : graph[u]) if (v != u) {
            if (res[v] != -1 && res[v] == res[u]) {
                cout << "IMPOSSIBLE";
                exit(0);
            }
            if (!dd[v]) {
                dd[v] = 1;
                res[v] = res[u] ^ 1;
                q.push(v);
            }
        }
    }
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
    for(int i = 1; i <= n; i++) res[i] = -1;
    for(int i = 1; i <= n; i++) if (!dd[i]) bfs(i);
    for(int i = 1; i <= n; i++) cout << res[i] + 1 << " ";
    
    return 0;
}