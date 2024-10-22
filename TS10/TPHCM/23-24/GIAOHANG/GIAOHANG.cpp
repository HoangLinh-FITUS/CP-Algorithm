#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solve(pair<int,int> arr[],int &n,int &m) {
    vector <pair<int,int>> path;
    for(int i = 0; i < n; i++) {
        int &x = arr[i].first;
        int &y = arr[i].second;
        if (x > y) path.push_back({x,y});
    }
    if (path.size() == 0) return m;
 
    sort(path.begin(),path.end());

    int Max = path.back().first;
    int Min = path.back().second;
    long long res = 0;
    for(int i = (int)path.size() - 1; i >= 0; i--) {
        int &x = path[i].first;
        int &y = path[i].second;
        if (Min <= x && x <= Max) Min = min(y,Min);
        else if (x < Min) {
            res += 2ll * (Max - Min);
            Max = x;
            Min = y;
        }
    }
    res += 2ll * (Max - Min);
    return res + m;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    pair <int,int> *a = new pair<int,int>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    cout << solve(a,n,m);
    return 0;
}