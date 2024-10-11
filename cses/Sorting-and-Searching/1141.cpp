#include <iostream>
#include <map>

using namespace std;
const int N = 2e5 + 1;

int n;
int k[N];
map <int, int> cnt;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k[i];

    int res = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && cnt[k[j]] == 0) {
            cnt[k[j]]++;
            j++;
        }
        res = max(res, j - i);
        cnt[k[i]]--;
    }
    cout << res;
    return 0;
}
