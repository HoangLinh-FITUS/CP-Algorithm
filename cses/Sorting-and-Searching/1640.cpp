#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map <int, int> pos;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        if (pos[x - ai] != 0) return cout << pos[x - ai] << " " << i, 0; 
        pos[ai] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}