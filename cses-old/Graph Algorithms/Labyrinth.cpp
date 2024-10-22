#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int N = 1e3 + 10;

int n,m;
char a[N][N];
pair<int,int> trace[N][N];

bool inside(int x,int y) {
    return 0 < x && x <= n && 0 < y && y <= m && a[x][y] == '.';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    pair <int,int> s,t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') s = {i,j},a[i][j] = '.';
            if (a[i][j] == 'B') t = {i,j},a[i][j] = '.';
        }
    }

    queue <pair<int,int>> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if (inside(u - 1,v)) {
            trace[u - 1][v] = {u,v};
            a[u - 1][v] = '#';
            q.push({u - 1,v});
        }
        if (inside(u + 1,v)) {
            trace[u + 1][v] = {u,v};
            a[u + 1][v] = '#';
            q.push({u + 1,v});
        }
        if (inside(u,v - 1)) {
            trace[u][v - 1] = {u,v};
            a[u][v - 1] = '#';
            q.push({u,v - 1});
        }
        if (inside(u,v + 1)) {
            trace[u][v + 1] = {u,v};
            a[u][v + 1] = '#';
            q.push({u,v + 1});
        }
    }
    if (a[t.first][t.second] == '.') return cout << "NO",0;
    cout << "YES\n";
    vector <pair<int,int>> res;
    while (t != s) {
        res.push_back(t);
        t = trace[t.first][t.second];
    }
    res.push_back(s);
    reverse(res.begin(),res.end());
    cout << res.size() - 1 << '\n';
    for(int i = 1; i < res.size(); i++) {
        if (res[i].first == res[i - 1].first) {
            if (res[i].second < res[i - 1].second) cout << "L";
            else cout << "R";
        }
        else {
            if (res[i].first < res[i - 1].first) cout << "U";
            else cout << "D";
        }
    }
    return 0;
}