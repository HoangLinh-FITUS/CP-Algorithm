#include <iostream>

using namespace std;
const int mod = 1e9 + 7;

int main() {
    long long n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                res += j;
                if (i / j != j) res += i / j;
            }
        }
    }
    cout << res;
    return 0;
}