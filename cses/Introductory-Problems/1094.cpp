#include <iostream>

using namespace std;

int main() {
    int n, prev = 0;
    cin >> n >> prev;

    long long res = 0;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        if (x < prev) {
            res += prev - x;
        }
        else prev = x;
    }
    
    cout << res;
    return 0;
}