#include <iostream>

using namespace std;

int cnt[(int)1e6 + 2];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int x,y;
        cin >> x >> y;
        cnt[y + 1]--;
        cnt[x]++;
    }
    int X = 0;
    for(int i = 1; i <= 1e6; i++) {
        cnt[i] += cnt[i - 1];
        X = max(X,cnt[i]);
    }
    int Y = 0;
    for(int i = 1; i <= 1e6; i++) Y += cnt[i] == X;
    cout << X << '\n' << Y;
    return 0;
}