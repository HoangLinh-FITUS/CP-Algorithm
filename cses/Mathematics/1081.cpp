#include <iostream>

using namespace std;
const int N = 1e6 + 1;

int n;
int cnt[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int res = 1;
    for (int i = 2; i < N; i++) {
        int C = 0;
        for (int j = i; j < N && C < 2; j += i) C += cnt[j];
        if (C > 1) res = max(res, i);
    }
    cout << res;
    return 0;
}