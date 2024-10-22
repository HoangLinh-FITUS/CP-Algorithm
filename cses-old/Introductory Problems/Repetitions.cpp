#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int res = 0;
    int i = 0,j = 0;
    while (i < s.size()) {
        j = i;
        while (j < s.size() && s[j] == s[i]) j++;
        res = max(res,j - i);
        i = j;
    }
    cout << res;
    return 0;
}