#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 1;

int n;
pair <int, int> Time[N];
int cnt[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> Time[i].first >> Time[i].second;

    sort(Time + 1, Time + n + 1);
   
    for (int i = n; i >= 1; i--) {
        cnt[i] = 1;
        int L = i + 1, R = n, pos = -1;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (Time[mid].first >= Time[i].second) {
                pos = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        if (pos != -1) cnt[i] = cnt[pos] + 1;
        cnt[i] = max(cnt[i], cnt[i + 1]);
    }

    cout << *max_element(cnt + 1, cnt + n + 1);

    return 0;
}