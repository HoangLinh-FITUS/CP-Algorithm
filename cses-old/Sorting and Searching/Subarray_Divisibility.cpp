#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    map <int,int> m;
    m[0] = 1;
    int s = 0;
    long long res = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s += x;
        s %= n;
        if (s < 0) s += n; 
        else if (s > n) s -= n;
        res += m[s] + m[s - n] + m[s - 2 * n];
        m[s]++;
    }
    cout << res;
    return 0;
}