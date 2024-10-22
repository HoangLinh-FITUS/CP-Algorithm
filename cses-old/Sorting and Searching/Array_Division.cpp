#include <iostream>

using namespace std;
const int N = 2e5 + 1;

int n,k;
int a[N];

bool check(long long x) {
    long long s = 0;
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        if (a[i] > x) return 0;
        s += a[i];
        if (s > x) {
            s = a[i];
            cnt++;
        }
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;       
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long L = 1,R = 1e15,res;
    while (L <= R) {
        long long mid = (L + R) / 2;
        if (check(mid)) {
            res = mid;
            R = mid - 1;
        } else L = mid + 1;
    }
    cout << res; 
    return 0;
}