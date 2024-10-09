#include <iostream>
#define NOSOL "NO SOLUTION"

using namespace std;

int main() {
    int n;
    cin >> n;
    int *res = new int[n + 1];
    res[0] = n;
    for (int i = 2; i <= n; i += 2) res[i] = res[0]--;
    for (int i = 1; i <= n; i += 2) res[i] = res[0]--;

    for (int i = 2; i <= n; i++) if (abs(res[i] - res[i - 1]) == 1) {
        return cout << NOSOL ,0;
    } 

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}