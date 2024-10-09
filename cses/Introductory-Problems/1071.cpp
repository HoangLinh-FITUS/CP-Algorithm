#include <iostream>

using namespace std;

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        int col, row;
        cin >> row >> col;
        
        long long S = max(row, col);
        if (S & 1) swap(row, col);
        S = S * S - S + 1 + row - col;
        cout << S << '\n';
    }

    return 0;
}