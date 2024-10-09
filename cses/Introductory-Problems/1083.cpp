#include <iostream>

using namespace std;

int cnt[(int)2e5 + 1];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        cnt[x] = 1;
    }
    for (int i = 1; i <= n; i++) if (cnt[i] == 0) {
        cout << i << " ";
    }
    return 0;
}