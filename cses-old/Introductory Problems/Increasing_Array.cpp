#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int pre = a[0];
    long long res = 0;
    for(int i = 1; i < n; i++) {
        if (a[i] - pre <= 0) res += pre - a[i];
        else pre = a[i];
    }
    cout << res;
    return 0;
}