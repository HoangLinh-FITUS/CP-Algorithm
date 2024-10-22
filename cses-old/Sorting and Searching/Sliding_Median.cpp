#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 2e5 + 1;

int n,k;
int a[N],BIT[N];

void upd(int x,int v) {
    for(; x < N; x += x & -x) BIT[x] += v;
}

int get(int x) {
    int cnt = 0;
    for(; x; x -= x & -x) cnt += BIT[x];
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector <int> com;
    for(int i = 0; i < n; i++) com.push_back(a[i]);
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());
    for(int i = 0; i < n; i++) a[i] = lower_bound(com.begin(),com.end(),a[i]) - com.begin() + 1;
    for(int i = 0; i < k - 1; i++) upd(a[i],1);
    for(int i = k - 1,j = 0; i < n; i++,j++) {
        upd(a[i],1);
        int res = 0;
        for(int L = 1,R = com.size(); L <= R; ) {
            int mid = (L + R) >> 1;
            if (get(mid) >= (k + 1) / 2) {
                res = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        cout << com[res - 1] << " ";
        upd(a[j],-1);
    }
    return 0;
}