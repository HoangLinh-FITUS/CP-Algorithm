#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    long long n,res = 0,pr = 5;
    cin >> n;
    while (pr <= n) {
        res += n / pr;
        pr *= 5;
    }
    cout << res;
    return 0;
}