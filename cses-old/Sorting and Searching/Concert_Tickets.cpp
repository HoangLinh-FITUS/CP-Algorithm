#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int m,n;
    cin >> m >> n;
    set <pair<int,int>> s;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.insert({x,i});
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = s.upper_bound({x,m});
        int res = -1;
        if (it != s.begin()) {
            it--;
            res = it->first; 
            s.erase(it);
        }
        cout << res << '\n';
    }
    return 0;
}