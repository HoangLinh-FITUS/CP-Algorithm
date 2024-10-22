#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    int res = 0;
    while (n--) {
        int type;
        cin >> type;
        if (type == 1) res += min(a,b);
        else res += a + b;
    }
    cout << res;
    return 0;
}