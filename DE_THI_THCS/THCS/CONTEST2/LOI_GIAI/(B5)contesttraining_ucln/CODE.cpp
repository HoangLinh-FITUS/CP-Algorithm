#include <bits/stdc++.h>

using namespace std;

long long N, X, ans = 1;

int main() {
    cin >> N >> X;
    if (N == 1) {
        cout << X;
        return 0;
    }
    for (long long i = 1; pow(i, N) <= X; i++) {
        if (X % (long long)pow(i, N) == 0) {
            ans = i;
        }
    }
    cout << ans;
}
