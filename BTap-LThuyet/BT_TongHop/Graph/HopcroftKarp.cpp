struct HCK
{
    int n, m;
    vi pU, pV, d;
    vector<vi> g;
    HCK(int _n, int _m) : n(_n), m(_m)
    {
        pU.assign(_n + 1, 0);
        pV.assign(_m + 1, 0);
        d.assign(_n + 1, 0);
        g.assign(_n + 1, vi(0));
    }
    void add(int u, int v)
    {
        g[u].eb(v);
    }
    bool bfs()
    {
        queue<int> q;
        FOR(i, 1, n) if (pU[i] == 0)
        {
            q.push(i);
            d[i] = 0;
        } else d[i] = INF;
        d[0] = INF;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (d[u] < d[0])
            {
                for (int v : g[u]) if (d[pV[v]] == INF)
                {
                    d[pV[v]] = d[u] + 1;
                    q.push(pV[v]);
                }
            } else break;
        }
        return d[0] != INF;
    }
    bool dfs(int u)
    {
        if (u)
        {
            for (int v : g[u]) if (d[pV[v]] == d[u] + 1 && dfs(pV[v]))
            {
                pU[u] = v;
                pV[v] = u;
                return 1;
            }
            d[u] = INF;
            return 0;
        }
        return 1;
    }
    int mmc()
    {
        int res = 0;
        while (bfs())
        {
            FOR(i, 1, n) if (pU[i] == 0 && d[i] != INF) res += dfs(i);
        }
        return res;
    }
};