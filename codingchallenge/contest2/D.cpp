#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;
const double eps = 1e-8;
const double INF = 1e15;

int N, M, X, Y;
pair <int, int> bridge[2001][2001];

struct Data {
    int vex;
    long long dis_a;
    int min_b;
    double dis;
    bool operator < (const Data& other) const {
        return dis > other.dis;
    }
};

double dist[2001];

void dijkstra(int S) {
    priority_queue <Data> q;
    for (int i = 1; i <= N; i++) dist[i] = INF;
    q.push({S, 0, (int)INF, 0});
    dist[S] = 0;
    while (!q.empty()) {
        int u = q.top().vex;
        long long du_a = q.top().dis_a;
        int min_b = q.top().min_b;
        double dis = q.top().dis;
        q.pop();
        if (dis != dist[u]) continue; 
        for (int v = 1; v <= N; v++) if (bridge[u][v].first != 0) {
            int a = bridge[u][v].first;
            int b = bridge[u][v].second;
            if (dist[v] > 1.0 * (du_a + a) / min(min_b, b)) {
                dist[v] = 1.0 * (du_a + a) / min(min_b, b);
                q.push({v, du_a + a, min(min_b, b), dist[v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> N >> M >> X >> Y;
    while (M--) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        bridge[u][v] = {a, b};
        bridge[v][u] = {a, b};
    }
    dijkstra(X);
    if (dist[Y] >= INF) cout << -1;
    else {
        cout << fixed << setprecision(6) << dist[Y]; 
    }
    return 0;
}