#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 1;

int n,m;
vector <pair<int,int>> adj[N];
long long dist[N][2];

struct Data {
    long long val;
    int ver;
    bool discount;
    friend bool operator < (const Data &other,const Data &x) {
        return other.val > x.val;
    } 
};


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,w,v;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    for(int i = 2; i <= n; i++) dist[i][0] = dist[i][1] = 1e18;
    priority_queue <Data> q;
    q.push({0,1,0});
    while (!q.empty()) {
        int u = q.top().ver;
        long long du = q.top().val;
        bool discount = q.top().discount;
        q.pop();
        if (du != dist[u][discount]) continue;
        for(auto i: adj[u]) {
            int v = i.first;
            int w = i.second;
            if (discount == 0) {
                if (dist[v][1] > dist[u][0] + w / 2) {
                    dist[v][1] = dist[u][0] + w / 2;
                    q.push({dist[v][1],v,1});
                }
                if (dist[v][0] > dist[u][0] + w) {
                    dist[v][0] = dist[u][0] + w;
                    q.push({dist[v][0],v,0});
                }
            } else {
                if (dist[v][1] > dist[u][1] + w) {
                    dist[v][1] = dist[u][1] + w;
                    q.push({dist[v][1],v,1});
                }
            }
        }
    }
    cout << dist[n][1];

    return 0;
}