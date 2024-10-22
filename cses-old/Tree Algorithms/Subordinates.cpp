#include <iostream>
#include <vector>

using namespace std;
const int N = 2e5 + 1;

vector <int> a[N];
int n;
int d[N];

void dfs(int u,int p = -1) {
    d[u] = 1;
    for(auto v : a[u]) if (v != p) {
        dfs(v);
        d[u] += d[v];
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << d[i] - 1 << " ";
    return 0;
}