#include <iostream>
#include <set>

using namespace std;
const int N = 2e5 + 1;

int n, m;

int main() {
    cin >> n >> m;

    set <pair<int,int>> S;
    for (int i = 1; i <= n; i++) {
        int hi;
        cin >> hi;
        S.insert({hi, i});
    }

    for (int i = 1; i <= m; i++) {
        int ti;
        cin >> ti;
        auto it = S.upper_bound({ti, n});
        if (it == S.begin()) cout << "-1\n";
        else {
            it--;
            cout << it->first << '\n';
            S.erase(it); 
        }
    }

    return 0;
}