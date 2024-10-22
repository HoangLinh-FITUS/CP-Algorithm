#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int x,n;
    cin >> x >> n;
    int *a = new int[n + 1];
    int *co = new int[n + 1];
    for(int i = 0; i < n; i++) cin >> a[i],co[i] = a[i];
    sort(a,a + n);
    a[n] = x;
    int pre = 0;
    set <pair<int,int>> s;
    int Max = 0;
    for(int i = 0; i <= n; i++) {
        s.insert({pre,a[i]});
        Max = max(Max,a[i] - pre);
        pre = a[i];
    }

    vector <int> res;
    for(int i = n - 1; i >= 0; i--) {
        res.push_back(Max);
        auto it = s.lower_bound({co[i],-1});
        int y = it->second;
        it--;
        int x = it->first;
        s.erase({x,co[i]});
        s.erase({co[i],y});
        s.insert({x,y});
        Max = max(Max,y - x);
    }
    for(auto it = res.rbegin(); it != res.rend(); it++) cout << *it << " ";
    return 0;
}