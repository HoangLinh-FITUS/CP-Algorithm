#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long toal_combination = 1ll * i * i * (i * i - 1) / 2;
        long long attracking_knights = 4ll * (i - 1) * (i - 2);
        cout << toal_combination - attracking_knights << '\n';
    }
    return 0;
}