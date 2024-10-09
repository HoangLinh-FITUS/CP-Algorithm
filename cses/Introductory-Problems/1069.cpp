#include <iostream>

using namespace std;

int main() {
    string st;
    cin >> st;
    int n = st.size();

    int res = 0;
    for (int i = 0, j = 0; i < n; i = j) {
        j = i;
        while (j < n && st[i] == st[j]) j++;
        res = max(res, j - i);
    }

    cout << res;
    return 0;
}