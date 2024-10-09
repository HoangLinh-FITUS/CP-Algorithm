#include <iostream>
#include <vector>

#define NOSOL "NO SOLUTION"

using namespace std;

int cnt[26];
char res[(int)1e6 + 1];
int l, r;
string st;

void process_even() {
    l = 0, r = st.size() - 1;
    for (int i = 0; i < 26; i++) if (cnt[i] > 0 && cnt[i] % 2 == 0) {
        char chr = i + 'A';
        while (cnt[i] > 0) {
            res[l] = res[r] = chr;
            l++, r--;
            cnt[i] -= 2;
        }
    }
}

bool process_odd() {
    int cntOdd = 0;
    for (int i = 0; i < 26; i++) if (cnt[i] & 1) {
        cntOdd++;
        if (cntOdd > 1) return 0;
        char chr = i + 'A';
        while (cnt[i] > 0) {
            res[l] = res[r] = chr;
            l++, r--;
            cnt[i] -= 2;
        }
    }
    return 1;
}

int main() {
    cin >> st;
    for (auto &i: st) cnt[i - 'A']++;

    for (int i = 0; i < st.size(); i++) res[i] = '#';

    process_even();
    if (process_odd() == 0) return cout << NOSOL, 0; 

    for (int i = 0; i < st.size(); i++) cout << (char)res[i];
    return 0;
}