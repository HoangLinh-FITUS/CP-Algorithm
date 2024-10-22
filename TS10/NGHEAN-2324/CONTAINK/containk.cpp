#include <iostream>
#define int long long 

using namespace std;

bool check(int number,const int &k,const long long &power) {
    while (number) {
        if (number % power == k) return 1;
        number /= 10;
    }
    return 0;
}

int32_t main() {
    int L,R,k;
    cin >> k >> L >> R;
    int power = 1;
    for(int Number = k; Number; Number /= 10) power *= 10;
    if (k == 0) power = 10;
    int res = 0;
    for(int i = L; i <= R; i++) res += check(i,k,power);
    cout << res;
    return 0;
}