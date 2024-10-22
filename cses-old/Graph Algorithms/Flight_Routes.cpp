#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int,int>> adj[100001];
int n,m,k;
int dd[100001];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    #define ii pair<long long,int>
    priority_queue <ii,vector<ii>,greater<ii>> q;
    q.push({0,1});
    while (!q.empty() && dd[n] < k) {
        int u = q.top().second;
        long long du = q.top().first;
        q.pop();
        dd[u]++;
        if (u == n) cout << du << " ";
        if (dd[u] <= k) {
            for(auto i: adj[u]) q.push({du + i.second,i.first});
        }
    }
    return 0;
}
