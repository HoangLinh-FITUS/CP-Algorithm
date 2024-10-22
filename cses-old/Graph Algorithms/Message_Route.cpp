#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 1;

int n,m;
vector <int> graph[N];
int dist[N];
int trace[N];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 2; i <= n; i++) dist[i] = 1e9;
    
    queue <int> q;
    q.push(1);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for(auto v : graph[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                trace[v] = u;
                q.push(v);
            }
        }
    }
    if (dist[n] == 1e9) return cout << "IMPOSSIBLE",0;
    cout << dist[n] + 1 << '\n'; 
    
    vector <int> res;
    while (n) {
        res.push_back(n);
        n = trace[n];
    }
    for(auto it = res.rbegin(); it != res.rend(); it++) cout << *it << " ";
    return 0;
}