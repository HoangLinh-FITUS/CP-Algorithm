#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ii pair<pair<int,int>,int>

const int N = 2e5 + 1,BLOCK = 400;

int n,q;
int a[N];
ii Query[N];

bool cmp(ii x,ii y) {
    if (x.first.first / BLOCK != y.first.first / BLOCK) return x.first.first / BLOCK < y.first.first / BLOCK;
    return x.first.second < y.first.second;
}

int res = 0;
int cnt[N];

void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) res++;
}

void sub(int x) {
    cnt[x]--;
    if (cnt[x] == 0) res--;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    vector <int> com;
    for(int i = 1; i <= n; i++) cin >> a[i],com.push_back(a[i]);
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(com.begin(),com.end(),a[i]) - com.begin() + 1;
    for(int i = 1; i <= q; i++) {
        cin >> Query[i].first.first >> Query[i].first.second;
        Query[i].second = i;
    }

    sort(Query + 1,Query + q,cmp);

    int L = 1,R = 0;
    vector <int> ans(n + 1,0);
    for(int i = 1; i <= q; i++) {
        int x = Query[i].first.first;
        int y = Query[i].first.second;
        int id = Query[i].second;
        while (L > x) add(a[--L]);
        while (L < x) sub(a[L++]);
        while (R < y) add(a[++R]);
        while (R > y) sub(a[R--]);
        ans[id] = res;
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}