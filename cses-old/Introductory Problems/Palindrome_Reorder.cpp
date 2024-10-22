#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    string st;
    cin >> st;
    int cnt[256]{0};
    for(auto i : st) cnt[i]++;
    int odd = 0;
    for(int i = 0; i < 256; i++) if (cnt[i] > 0) odd += cnt[i] & 1;
    if ((st.size() & 1) && odd != 1) return cout << "NO SOLUTION\n",0;
    if (st.size() % 2 == 0 && odd > 0) return cout << "NO SOLUTION\n",0;  

    int d = 0,c = st.size();
    char *a = new char[c];
    for(int i = 0; i < c; i++) a[i] = '*';
    for(int i = 0; i < 256; i++) if (cnt[i] > 0 && cnt[i] % 2 == 0) {
        while (cnt[i] > 0) {
            a[d++] = char(i);
            a[--c] = char(i);
            cnt[i] -= 2;
        }
    }
    for(int i = 0; i < 256; i++) if (cnt[i] > 0 && cnt[i] % 2 != 0) {
        while (cnt[i] > 0) {
            a[d++] = char(i);
            a[--c] = char(i);
            cnt[i] -= 2;
        }
    }
    for(int i = 0; i < st.size(); i++) cout << a[i];
    return 0;
}