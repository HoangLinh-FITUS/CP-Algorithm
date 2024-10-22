#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int N;
    cin >> N;
    while (N--) {
        int i,j;
        cin >> i >> j;
        long long S = max(i,j);
        if (S & 1) swap(i,j);
        S = S*S - S + 1 + i - j;
        cout << S << '\n';
    }
    return 0;
}