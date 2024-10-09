#include <iostream>

using namespace std;

int main() {
    long long n, res = 0, pr = 5;
    cin >> n;
    while (pr <= n) {
        res += n / pr;
        pr *= 5;
    }
    cout << res;
    return 0;
}