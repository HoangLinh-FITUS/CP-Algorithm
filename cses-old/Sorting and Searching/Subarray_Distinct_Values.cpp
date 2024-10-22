#include <iostream>
#include <map>
#include <set>

using namespace std;
const int N = 2e5 + 1;

int n,k;
int a[N],t[N];
map <int,int> cnt;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int dis = 0;
    for(int i = 0,j = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) dis++;
        while (j < n && dis > k) {
            cnt[a[j]]--;
            if (cnt[a[j]] == 0) dis--;
            j++;
        }
        t[j] = max(t[j],i);
    }
    for(int i = 0; i < n; i++) t[i] = max(t[i],t[i - 1]);

    long long res = 0;
    for(int i = 0; i < n; i++) {
        int x = t[i] - i;
        res += x;
    }
    cout << res + n;
    return 0;
}