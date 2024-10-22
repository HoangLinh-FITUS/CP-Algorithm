#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 2e5 + 100;

int seg[N * 4];
int n;

void upd(int pos,int val,int id = 1,int l = 1,int r = n) {
    if (l == r) {
        seg[id] = max(seg[id],val);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) upd(pos,val,id << 1,l,mid);
    else upd(pos,val,id << 1 | 1,mid + 1,r);
    seg[id] = max(seg[id << 1],seg[id << 1 | 1]);
}

int get(int u,int v,int id = 1,int l = 1,int r = n) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return max(get(u,v,id << 1,l,mid),get(u,v,id << 1 | 1,mid + 1,r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    int *a = new int[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    vector <int> com;
    for(int i = 1; i <= n; i++) com.push_back(a[i]);
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());

    for(int i = 1; i <= n; i++) a[i] = lower_bound(com.begin(),com.end(),a[i]) - com.begin() + 1;
    
    for(int i = 1; i <= n; i++) {
        cout << get(1,a[i] - 1) << " ";
        upd(a[i],i);
    }
    return 0;
}