#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[(int)2e5 + 1];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1,a + n + 1);

    long long X = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > X) return cout << X, 0;
        X += a[i];
    }
    cout << X;
    return 0;
}