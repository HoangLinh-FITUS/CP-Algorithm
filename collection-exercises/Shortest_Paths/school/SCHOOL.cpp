#include <bits/stdc++.h>
#define maxn 5005

using namespace std;
typedef pair<int,int> II;

int n, m, deg[maxn];
vector<II> g[maxn];
set<II> q;
int cl[maxn], kc[maxn], x[maxn], slx=0;
int64_t f[maxn];


void Dijkstra(int xp) {
    q.clear();
    cl[xp]=1; kc[xp]=0; q.insert(II(kc[xp],xp));
    while (!q.empty()) {
        II t=*q.begin(); q.erase(t);
        int u=t.second; x[++slx]=u; cl[u]=2;
        for(int i=0;i<deg[u];++i) {
            int v=g[u][i].first, L=g[u][i].second;
            if (cl[v]==0) {
                cl[v]=1; kc[v]=kc[u]+L;
                q.insert(II(kc[v],v));
            } else if (cl[v]==1 && kc[v]>kc[u]+L) {
                q.erase(II(kc[v],v));
                kc[v]=kc[u]+L;
                q.insert(II(kc[v],v));
            }
        }
    }
}

int main() {
    freopen("school.inp","r",stdin);
    freopen("school.out","w",stdout);
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;++i) {
        int loai, u, v, w;
        scanf("%d %d %d %d", &loai, &u, &v, &w);
        g[u].push_back(II(v,w)); ++deg[u];
        if (loai==2) {
            g[v].push_back(II(u,w));
            ++deg[v];
        }
    }
    Dijkstra(1);
    for(int i=1;i<=n;++i) f[i]=0;
    for(int i=1;i<=slx;++i) {
        int u=x[i];
        if (u==1) f[u]=1;
        for(int j=0;j<deg[u];++j) {
            int v=g[u][j].first, L=g[u][j].second;
            if (kc[v]==kc[u]+L) f[v] += f[u];
        }
    }
    printf("%d %I64d\n",kc[n], f[n]);
}
