#include <iostream>

using namespace std;

int n;
int a[(int)2e5 + 2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    
    int res = 1;
    for (int i = 2; i <= n; i++) res += a[i - 1] > a[i];
    cout << res;
    return 0;
}