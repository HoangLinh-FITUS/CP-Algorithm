#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    #define ii pair<pair<int,int>,int>
    ii *a = new ii[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a,a + n);
    set <pair<int,int>> s;
    s.insert({a[0].first.second,1});
    int *res = new int[n];
    res[a[0].second] = 1;
    int Max = 1;
    for(int i = 1; i < n; i++) {
        if (s.begin()->first < a[i].first.first) {
            int p = s.begin()->second;
            res[a[i].second] = p;
            s.erase(s.begin());
            s.insert({a[i].first.second,p});
        } else {
            res[a[i].second] = ++Max;
            s.insert({a[i].first.second,Max});
        }
    }
    cout << Max << '\n';
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    return 0;
}