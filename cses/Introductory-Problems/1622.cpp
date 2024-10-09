#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;

int main() {
    string st;
    cin >> st;
    sort(st.begin(), st.end());
    set <string> s;
    do {   
        s.insert(st);
    } while (next_permutation(st.begin(), st.end()));
    cout << s.size() << '\n';
    for (auto &i: s) cout << i << '\n';
}