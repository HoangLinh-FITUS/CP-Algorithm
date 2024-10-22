#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 2e5 + 1;

char type[N];
int a[N],x[N],y[N];
int n,q;
int BIT[N * 4];

void upd(int x,int val) {
    for(; x < N * 4; x += x & -x) BIT[x] += val;
}

int get(int x) {
    int sum = 0;
    for(; x; x -= x & -x) sum += BIT[x];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> type[i] >> x[i] >> y[i];
    vector <int> com;
    for(int i = 1; i <= n; i++) com.push_back(a[i]);
    for(int i = 1; i <= q; i++) {
        com.push_back(y[i]);
        if (type[i] == '?') com.push_back(x[i]);
    }
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(com.begin(),com.end(),a[i]) - com.begin() + 1;
    for(int i = 1; i <= q; i++) {
        y[i] = lower_bound(com.begin(),com.end(),y[i]) - com.begin() + 1;
        if (type[i] == '?') x[i] = lower_bound(com.begin(),com.end(),x[i]) - com.begin() + 1;
    }

    for(int i = 1; i <= n; i++) upd(a[i],1);

    for(int i = 1; i <= q; i++) {
        if (type[i] == '?') cout << get(y[i]) - get(x[i] - 1) << '\n';
        else {
            upd(a[x[i]],-1);
            a[x[i]] = y[i];
            upd(y[i],1);
        }
    }

    return 0;
}