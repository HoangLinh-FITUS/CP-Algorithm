#include <iostream>

using namespace std;

bool kt(long long x, int L, long long N) {
    long long S = 1;
    for (int i = 0; i < L; i++) {
        if (S > 1.0 * N / (x + i)) return false;
        S *= (x + i);
    }
    return S == N;
}

long long calc(int L, long long N) {
    long long x = 0;
    for(long long le = 1, re = N; le <= re; ) {
        long long mid = (le + re) / 2;
        long long S = 1;
        bool ok = 0;
        for (int i = 0; i < L; i++) {
            if (S > 1.0 * N / (mid + i)) {
                ok = 1;
            }
            S *= (mid + i);
        }
        if (!ok) {
            x = mid;
            le = mid + 1;
        } 
        else {
            re = mid - 1;
        }
    }
    return x;
}

bool check(int L, long long N) {
    long long x = calc(L, N);
    return kt(x, L, N);
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int Q;
    cin >> Q;
    while (Q--) {
        long long N;
        cin >> N;
        long long x = N;
        pair <long long, long long> res = {N, N - 1};
        for (int L = 2; L <= 20; L++) 
        {
            if (check(L, N)) {
                long long x = calc(L, N);
                res = min(res, {x + L - 1, x - 1});
            }
        }
        cout << res.first << " " << res.second << '\n';
    }
    return 0;
}