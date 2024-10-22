#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a + n);
    int mid = n / 2;
    long long res = 0;
    for(int i = 0; i < n; i++) res += abs(a[i] - a[mid]);
    cout << res;
    return 0;
}