#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    map <int,int> cnt;
    int res = 1;
    for(int i = 0,j = 0; i < n; i++) {
        cnt[a[i]]++;
        while (j < i && cnt[a[i]] > 1) {
            cnt[a[j]]--;
            j++;
        }
        res = max(res,i - j + 1);
    }
    cout << res;

    return 0;
}