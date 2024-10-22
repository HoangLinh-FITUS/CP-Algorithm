#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    pair <int,int> *a = new pair<int,int>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a,a + n);
    int *cnt = new int[n + 1]{0};
    for(int i = n - 1; i >= 0; i--) {
        cnt[i] = 1;
        int j = i + 1;
        for(int l = i + 1,r = n - 1; l <= r; ) {
            int mid = (l + r) / 2;
            if (a[i].second <= a[mid].first) {
                j = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        if (a[i].second <= a[j].first) cnt[i] = cnt[j] + 1;
        cnt[i] = max(cnt[i + 1],cnt[i]);
    }
    cout << *max_element(cnt,cnt + n);
    return 0;
}