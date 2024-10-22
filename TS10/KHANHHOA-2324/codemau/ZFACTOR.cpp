#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin >> n >> k;
    int *smallestP = new int[k + 1]{0};
    int *cnt = new int[k + 1]{0};
    for(int i = 2; i <= k; i++) if (!smallestP[i]) {
        for(int j = i; j <= k; j += i) {
            if (!smallestP[j]) smallestP[j] = i;
        }
    }
    for(int i = 2; i <= k; i++) cnt[smallestP[i]]++;
    
    while (n--) {
        int x;
        cin >> x;
        cout << cnt[x] << '\n';
    }
    return 0;
}