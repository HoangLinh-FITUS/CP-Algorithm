#include <iostream>
#include <vector>

using namespace std;
const int N = 101;

long long a[N];
int L,R;

long long getsum(long long *sum, int l, int r) {
    return sum[r] - sum[l - 1];
}

int calc(int n) {
    if (n == 1) return 0;

    long long *sum = new long long[n + 1]{0};
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    for (int i = 1; i <= n; i++) {
        for (int len = L; len <= R && i + len - 1 <= n; len++) {
            int S = getsum(sum, i, i + len - 1);
            
        }    
    }
}

int n;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout<< calc(n);
    
    return 0;
}