#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a,b;
        cin >> a >> b;
        int x = (2 * a - b) / 3;
        int y = (2 * b - a) / 3;
        if (x < 0 || y < 0) cout << "NO\n";
        else if (2 * x + y == a && x + 2 * y == b) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}