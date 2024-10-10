#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 4e5 + 10;

int Time[N], a[N], b[N];
int n;
 
int main() {
    int n;
    cin >> n;
    vector <int> com;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        com.push_back(a[i]);
        com.push_back(b[i]);
    }

    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());

    for (int i = 1; i <= n; i++) {
        int ta = lower_bound(com.begin(), com.end(), a[i]) - com.begin() + 1; 
        int tb = lower_bound(com.begin(), com.end(), b[i]) - com.begin() + 1; 
        Time[ta]++;
        Time[tb + 1]--;
    }

    int res = 0;
    for (int i = 1; i <= com.size(); i++) {
        Time[i] += Time[i - 1];
        res = max(res, Time[i]);
    }

    cout << res;
    return 0;
}