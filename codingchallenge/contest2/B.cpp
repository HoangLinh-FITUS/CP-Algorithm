#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map <int,int> cnt, min_pos;

bool cmp(int x, int y) {
    if (cnt[x] != cnt[y]) return cnt[x] < cnt[y];
    return min_pos[x] < min_pos[y];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, C;
    cin >> n >> C;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = n - 1; i >= 0; i--) min_pos[a[i]] = i;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}