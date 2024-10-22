#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
const int N = 1e4 + 1;

int num[N],low[N],del[N];
int n,m;
vector <int> Graph[N];
stack <int> st;
int TPLT = 0;

void Tarjan(int u) {
    num[u] = ++num[0];
    low[u] = num[u];
    st.push(u);
    for(auto v : Graph[u]) {
        if (del[v]) continue;
        if (!num[v]) {
            Tarjan(v);
            low[u] = min(low[v],low[u]);
        } else low[u] = min(low[u],num[v]);
    }
    if (low[u] == num[u]) {
        int v;
        TPLT++;
        del[u] = 1;
        do {
            v = st.top();
            del[v] = 1;
            st.pop();
        } while (u != v);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        Graph[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) if (!num[i]) Tarjan(i);
    cout << TPLT;
    return 0;
}