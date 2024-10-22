#include <iostream>

using namespace std;

string str,pat;
int kmp[(int)2e6 + 8];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> str >> pat;
    str = pat + "#" + str;
    kmp[0] = 0;
    for(int i = 1; i < str.size(); i++) {
        int j = kmp[i - 1];
        while (j > 0 && str[j] != str[i]) j = kmp[j - 1];
        if (str[i] == str[j]) j++;
        kmp[i] = j;
    }
    int res = 0;
    for(int i = pat.size(); i < str.size(); i++) if (kmp[i] == pat.size()) res++;
    cout << res;
    return 0;
}