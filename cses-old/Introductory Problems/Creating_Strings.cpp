#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    string st;
    cin >> st;
    sort(st.begin(),st.end());
    vector <string> res;
    do {
        res.push_back(st);
    } while (next_permutation(st.begin(),st.end()));
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    cout << res.size() << '\n';
    for(auto i : res) cout << i << '\n';
    return 0;
}