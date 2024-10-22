#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    n--;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a + n);
    if (a[0] != 1) cout << 1;
    else {
        bool ok = 0;
        for(int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] != 1) {
                cout << a[i - 1] + 1;
                ok = 1;
                break;
            }
        }
        if (!ok) cout << a[n - 1] + 1;
    }
    return 0;
}