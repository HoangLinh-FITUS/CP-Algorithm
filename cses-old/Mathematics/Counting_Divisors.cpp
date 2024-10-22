#include <iostream>

using namespace std;
const int LIMIT = 1e6;

int main() {
    int *least_prime = new int[LIMIT + 1]{0};
    for(int i = 1; i <= LIMIT; i++) least_prime[i] = i;
    for(int i = 2; i * i <= LIMIT; i++) if (least_prime[i] == i) {
        for(int j = i + i; j <= LIMIT; j += i) least_prime[j] = i;
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        long long res = 1;
        while (x != 1) {
            int z = least_prime[x];
            int c = 0;
            while (x % z == 0) x /= z,c++;
            res *= (c + 1);
        }
        cout << res << '\n';
    }
    return 0;
}