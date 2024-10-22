#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector <pair<int,int>> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({x,i + 1});
    }
    sort(a.begin(),a.end());
    int cnt = 1;
    for(int i = 1; i < n; i++) if (a[i - 1].second > a[i].second) cnt++;
    while (q--) {
        int x,y;
        cin >> x >> y;
        swap(a[x - 1].second,a[y - 1].second);
    }
    return 0;
}