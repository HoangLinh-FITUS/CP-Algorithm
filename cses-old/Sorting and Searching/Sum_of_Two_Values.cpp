#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    int x;
    cin >> n >> x;
    map <int,int> m;
    for(int i = 0; i < n; i++) {
        int y;
        cin >> y;
        if (m[x - y]) {
            cout << m[x - y] << " " << i + 1;
            return 0;
        } 
        m[y] = i + 1;
    }
    cout << "IMPOSSIBLE";

    return 0;
}