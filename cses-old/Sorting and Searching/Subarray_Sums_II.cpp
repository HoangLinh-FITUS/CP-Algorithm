#include <iostream>
#include <map>

using namespace std;
const int N = 2e5 + 1;

long long a[N];
int n,x;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long res = 0;
    map <long long,int> m;
    for(int i = n; i >= 1; i--) {
        m[a[i]]++;
        res += m[x + a[i - 1]];
    }
    cout << res;
    return 0;
}