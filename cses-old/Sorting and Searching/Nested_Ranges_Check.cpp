#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
const int N = 2e5 + 1;

int n;
pair<pair<int,int>,int> a[N];
int res1[N],res2[N]; // ket qua cua de bai 
vector <int> com;
int BIT[2 * N];

void upd(int x,int value) {
    for(; x < 2 * N; x += x & -x) BIT[x] += value;
}

int get(int x) {
    int sum = 0;
    for(; x; x -= x & -x) sum += BIT[x];
    return sum;
}

bool cmp1(pair<pair<int,int>,int> &x,pair<pair<int,int>,int> &y) {
    if (x.first.first == y.first.first) {
        return x.first.second > y.first.second;
    }
    return x.first.first < y.first.first;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        com.push_back(a[i].first.first);
        com.push_back(a[i].first.second);
        a[i].second = i;
    }

    sort(a,a + n,cmp1);
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());

    for(int i = n - 1; i >= 0; i--) {
        a[i].first.first = lower_bound(com.begin(),com.end(),a[i].first.first) - com.begin() + 2;
        a[i].first.second = lower_bound(com.begin(),com.end(),a[i].first.second) - com.begin() + 2;
        res1[a[i].second] = get(a[i].first.second);
        upd(a[i].first.second,1);
    }
    
    memset(BIT,0,sizeof(BIT));
    for(int i = 0; i < n; i++) {
        res2[a[i].second] = get(2 * N - 1) - get(a[i].first.second - 1);
        upd(a[i].first.second,1);
    }

    for(int i = 0; i < n; i++) cout << (res1[i] != 0) << " \n"[i == n - 1];
    for(int i = 0; i < n; i++) cout << (res2[i] != 0) << " ";
    return 0;
}