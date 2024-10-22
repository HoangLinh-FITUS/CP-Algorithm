#include <iostream>
#include <algorithm>

using namespace std;
#define int long long 

const int N = 5e2 + 1;

pair <int,int> a[N];
int n,x;

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a,a + n);

    for(int i = 0; i < n; i++) {
        int target = x - a[i].first;
        for(int j = i + 1,k = i + 1; j < n; j++) {
            while (k < j && a[k].first < target - a[j].first) k++;
            while (k > i && a[k].first > target - a[j].first) k--;
            if (i < k && k < j && a[j].first + a[k].first == target) {
                int x = a[i].second;
                int y = a[j].second;
                int z = a[k].second;
                if (x > y) swap(x,y);
                if (x > z) swap(x,z);
                if (y > z) swap(y,z);
                cout << x + 1 << " " << y + 1 << " " << z + 1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}