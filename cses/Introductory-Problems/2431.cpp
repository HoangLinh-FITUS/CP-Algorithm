#include <iostream>
#include <string>
#define int long long 

using namespace std;

char get(int k) {
    k--;
    int power10 = 1, num = 0;
    for (int cntDigit = 1; cntDigit <= 18; cntDigit++) {
        int numMin = 1 * power10;
        int numMax = power10 * 10 - 1;
        int C = (numMax - numMin + 1) * cntDigit;
        if (k <= C) {
            num = numMin + k / cntDigit;
            k %= cntDigit;
            break;
        }
        k -= C;
        power10 *= 10;
    }
    string res = to_string(num);
    return res[k];
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        cout << get(k) << '\n';
    } 
}