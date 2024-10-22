#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int res = 1;
    for(int i = 1; i <= n; i++) (res *= 2) %= ((int)1e9 + 7);
    cout << res;
    return 0;
}