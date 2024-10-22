#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    int x = 2;
    for(int i = 0; i < n; i++) {
        if (x > n) x = 1;
        a[i] = x;
        x += 2;
    }
    for(int i = 1; i < n; i++) if (abs(a[i] - a[i - 1]) == 1) return cout << "NO SOLUTION",0;
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}