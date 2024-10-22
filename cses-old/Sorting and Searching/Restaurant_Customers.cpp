#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    pair <int,int> *a = new pair<int,int>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a,a + n);
    
    vector <int> com;
    for(int i = 0; i < n; i++) com.push_back(a[i].first),com.push_back(a[i].second);
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());

    int* cnt = new int[com.size() + 1]{0};
    for(int i = 0; i < n; i++) {
        a[i].first = lower_bound(com.begin(),com.end(),a[i].first) - com.begin() + 1;
        a[i].second = lower_bound(com.begin(),com.end(),a[i].second) - com.begin() + 1;

        cnt[a[i].second + 1]--;
        cnt[a[i].first]++;
    }

    for(int i = 1; i <= com.size(); i++) cnt[i] += cnt[i - 1];

    cout << *max_element(cnt,cnt + com.size());

    return 0;
}