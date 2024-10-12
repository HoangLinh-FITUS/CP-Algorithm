#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
const int N = 2e5 + 1;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 3 8 2 1 5 
    // S = {3}
    // S = {3, 8}
    // S = {2, 8}
    // S = {1, 8}
    // S = {1, 5}
    set <pair<int,int>> S;
    for (int i = 1; i <= n; i++) {
        auto it = S.upper_bound({a[i], i});
        if (it != S.end()) S.erase(it);
        S.insert({a[i], i});
    }    

    cout << S.size();
    return 0;
}