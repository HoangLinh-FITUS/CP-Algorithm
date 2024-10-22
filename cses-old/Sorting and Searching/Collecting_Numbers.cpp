#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n + 1]{0};
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = i + 1;
    }
    int res = 1;
    for(int i = 2; i <= n; i++) res += a[i - 1] > a[i];
    cout << res;
    return 0;
}