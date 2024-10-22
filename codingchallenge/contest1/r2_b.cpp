#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int A = i > 0 ? a[0] : a[n - 1];
            int B = i > 0 ? a[0] : a[n - 1];
            for (int j = 0; j < i - 1; j++) A &= a[j], B |= a[j];
            for (int j = i + 1; j < n; j++) A &= a[j], B |= a[j];
            for (int x = 0; x < (1 << 10); x++) {
                int tmpA = A & x;
                int tmpB = B | x;
                if (tmpA != tmpB) {
                    cout << i + 1 << " " << x << '\n';
                    goto ret;
                }
            }
        }
        ret:
        continue;
    }
    return 0;
}