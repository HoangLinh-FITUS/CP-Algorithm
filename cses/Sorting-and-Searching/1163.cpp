#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
const int N = 2e5 + 2;

int x, n;
int p[N], copyP[N], res[N];

int main() {
    cin >> x >> n;
    for (int i = 1; i <= n; i++) cin >> p[i], copyP[i] = p[i];
    sort(p + 1, p + n + 1);

    int previous = 0, Max = 0;
    set <pair<int,int>> S;
    p[n + 1] = x;
    for(int i = 1; i <= n + 1; i++) {
        S.insert({previous, p[i]});
        Max = max(Max, p[i] - previous);
        previous = p[i];
    }   

    for (int i = n; i >= 1; i--) {
        res[i] = Max;
        auto it = S.lower_bound({copyP[i], copyP[i] + 1});
        int y = it->second;
        it--;
        int x = it->first;
        S.erase({x, copyP[i]});
        S.erase({copyP[i], y});
        S.insert({x, y});
        Max = max(Max, y - x);
    }

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    
    return 0;
}