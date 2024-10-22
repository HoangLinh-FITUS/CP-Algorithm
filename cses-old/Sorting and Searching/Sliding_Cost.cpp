#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

#define int long long

using namespace std;
const int N = 2e5 + 1;

int n,k;
int a[N];

struct FewichTree {
    int BIT[N];
    FewichTree() {
        memset(BIT,0,sizeof(BIT));
    }
    void upd(int x,int v) {
        for(; x < N; x += x & -x) BIT[x] += v;
    }

    int get(int x) {
        int cnt = 0;
        for(; x; x -= x & -x) cnt += BIT[x];
        return cnt;
    }
};

FewichTree BIT1,BIT2;

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector <int> com;
    for(int i = 0; i < n; i++) com.push_back(a[i]);
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());
    for(int i = 0; i < n; i++) a[i] = lower_bound(com.begin(),com.end(),a[i]) - com.begin() + 1;
    for(int i = 0; i < k - 1; i++) BIT1.upd(a[i],1);
    int st = 0,ed = 0;
    int cost = 0;
    for(int i = k - 1,j = 0; i < n; i++,j++) {
        BIT1.upd(a[i],1);
        int res = 0;
        for(int L = 1,R = com.size(); L <= R; ) {
            int mid = (L + R) >> 1;
            if (BIT1.get(mid) >= (k + 1) / 2) {
                res = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        int l1 = BIT1.get(res);
        BIT1.upd(a[j],-1);
        //=================================

        int x = com[res - 1];
        while (ed - st < k) {
            BIT2.upd(a[ed],com[a[ed] - 1]);
            cost += com[a[ed] - 1];
            ed++;
        }
        
        int l2 = k - l1;
        int S1 = BIT2.get(res);
        int S2 = cost - S1;
        cout << x * l1 - S1 + S2 - x * l2 << " ";
        BIT2.upd(a[st],-com[a[st] - 1]);
        cost -= com[a[st] - 1];
        st++;
    }
    return 0;
}