#include <iostream>
#include <set>

using namespace std;
const int N = 2e5 + 1;

int n,m;
int a[N];
int ST[N * 4];

void build(int id = 1,int l = 1,int r = n) {
    if (l == r) {
        ST[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1,l,mid);
    build(id << 1 | 1,mid + 1,r);
    ST[id] = max(ST[id << 1],ST[id << 1 | 1]);
}

void get(int x,int id = 1,int l = 1,int r = n) {
    if (l == r) {
        ST[id] -= x;
        cout << l << " ";
        return;
    }
    int mid = (l + r) >> 1;
    if (ST[id * 2] >= x) get(x,id << 1,l,mid);
    else get(x,id << 1 | 1,mid + 1,r);
    ST[id] = max(ST[id << 1],ST[id << 1 | 1]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    while (m--) {
        int x;
        cin >> x;
        if (ST[1] < x) cout << "0 ";
        else get(x);
    }
    return 0;
}