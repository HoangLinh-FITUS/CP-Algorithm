#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 1;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int numMid = a[(n + 1) >> 1];
    long long res = 0;
    for (int i = 1; i <= n; i++) res += abs(a[i] - numMid);
    cout << res;
    return 0;
}