#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        string s;
        cin >> s;
        int cnt[26];
        for (int i = 0; i < 26; i++) cnt[i] = 0;
        int pos = 0;
        for (auto i: s) cnt[i - 'a']++, pos = i - 'a';
        for (auto i: s) if (cnt[i - 'a'] > cnt[pos]) pos = i - 'a';
        cout << (s.size() - cnt[pos]) << '\n';
    }
    return 0;
}