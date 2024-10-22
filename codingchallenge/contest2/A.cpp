#include <iostream>
#include <math.h>

using namespace std;

int sum(long long x) {
    int S = 0;
    while (x > 0) {
        S += x % 10;
        x /= 10;
    }
    return S;
}

int main() {
    long long N;
    cin >> N;
    long long res = -1;
    for (int Sx = 0; Sx <= 9 * 18; Sx++) {
        // x^2 + Sx*x - N = 0
        int a = 1;
        int b = Sx;
        long long c = -N;
        // ax^2 + bx + c = 0
        long long denta = b*b - 4 * a * c;
        if (denta < 0) continue;
        long long x1 = (-b - sqrt(denta)) / (2 * a);
        long long x2 = (-b + sqrt(denta)) / (2 * a);
        long long x;
        if (x1 >= 0) {
            x = x1;
            if (sum(x) == Sx && x * x + Sx * x == N) {
            cout << x * x + Sx*x - N << '\n';
            if (res == -1) res = x;
            else res = min(res, x);
        }    
        }
        if (x2 >= 0) {
            x = x2;
            if (sum(x) == Sx && x * x + Sx * x == N) {
                if (res == -1) res = x;
                else res = min(res, x);
            }
        }
            
    }
    cout << res;
    return 0;
}