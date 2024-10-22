#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int a[1005][1005];
int match[1005];
int vis[1005];
int cur,n;

bool dfs(int u, int x)
{
    if (vis[u] == cur) return false;
    vis[u] = cur;
    for (int v = 1; v <= n; v++) if (a[u][v] >= x && !match[v])
    {
        match[v] = u;
        return true;
    }
    for (int v = 1; v <= n; v++) if (a[u][v] >= x && dfs(match[v], x))
    {
        match[v] = u;
        return true;
    }
    return false;
}

bool solve(int x)
{
    memset(match, 0, sizeof(match));
    memset(vis, 0, sizeof(vis));
    cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur++;
        if (!dfs(i, x)) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        cin >> a[i][j];
    }
    int lo = 0;
    int hi = (int) 1e9 + 1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) >> 1;
        if (solve(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}
