#include <iostream>

using namespace std;
const int N = 1e6 + 1;

int a[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }   

    for(int G = 1e6; G >= 2; G--) {
        int cnt = 0;
        for(int j = G; j <= 1e6; j += G) cnt += a[j];
        if (cnt >= 2) return cout << G,0;
    }
    cout << 1;
    return 0;
}