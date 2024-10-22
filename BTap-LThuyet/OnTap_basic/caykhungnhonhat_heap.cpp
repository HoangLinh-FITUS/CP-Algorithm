#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e4 + 1;

vector <tuple<int,int,int>> e;
int n,m;
int par[N];

int Find(int u) {
    return par[u] == u ? u : par[u] = Find(par[u]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    while (m--) {
        int u,v,c;
        cin >> u >> v >> c;
        e.push_back({c,u,v});
    }
    sort(e.begin(),e.end());
    int coinMin = 0;
    for(auto i : e) {
        int c = get<0>(i),u = get<1>(i),v = get<2>(i);
        int x = Find(u),y = Find(v);
        if (x != y) {
            coinMin += c;
            par[y] = x;
        }
    }
    cout << coinMin;
    return 0;

}