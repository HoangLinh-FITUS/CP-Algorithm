struct dinic
{
        ll n;
        vector <set<ll>> adj;
        vector <vector<ll>> cap;

        dinic(ll n) : n(n)
        {
                adj.assign(n + 1, set <ll> ());
                cap.assign(n + 1, vector <ll> (n + 1, 0));
        }

        void add_edge(ll u, ll v, ll w)
        {
                adj[u].insert(v);
                adj[v].insert(u);
                cap[u][v] += w;
        }

        ll bfs(ll s, ll t)
        {
                queue <pair <ll, ll> > qu;
                vector <ll> trace(n + 1, -1);
                qu.push({s,INF});
                trace[s] = 0;
                ll res = 0;
                while (!qu.empty())
                {
                        ll u,f;
                        tie(u, f) = qu.front();
                        qu.pop();
                        if (u == t)
                        {
                            res = f;
                            break;
                        }
                        for (auto v : adj[u])
                        {
                            if (trace[v] == -1 && cap[u][v] > 0)
                            {
                                trace[v] = u;
                                qu.push({v, min(f, cap[u][v])});
                            }
                        }
                }
                if (!res) return 0;
                for (ll u = trace[t], v = t; v != s; v = u, u = trace[u])
                {
                        cap[u][v] -= res;
                        cap[v][u] += res;
                }
                return res;
        }

        ll maxflow(ll s, ll t)
        {
                ll res = 0;
                while (ll f = bfs(s, t)) res += f;
                return res;
        }

        void dfs(ll u, vector <bool> &vis)
        {
                vis[u] = true;
                for (auto v : adj[u])
                {
                        if (vis[v]) continue;
                        if (cap[u][v]) dfs(v, vis);
                }
        }

        auto minCut(ll s)
        {
                vector <bool> vis(n + 1, false);
                dfs(s, vis);
                vector <ii> res;
                For(u, 1, n) for (auto v : adj[u])
                    if (vis[u] && !vis[v] && cap[v][u])  res.push_back({u,v});
                return res;
        }
};