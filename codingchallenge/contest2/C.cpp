#include <iostream>
#include <queue>

using namespace std;

struct Data {
    int L, R, len;
    bool operator < (const Data& other) const {
        if (other.len == len) {
            return L < other.L;
        }
        return len < other.len;
    }
};

int a[(int)5e5 + 10];

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) a[i] = 0;
        priority_queue <Data> q;
        q.push({1, N, N});
        int i = 0;
        while (!q.empty()) {
            int L = q.top().L;
            int R = q.top().R;
            int len = q.top().len;
            q.pop();
            int mid = (L + R) / 2;
            if (a[mid] == 0) {
                a[mid] = ++i;
                q.push({L, mid - 1, mid - L});
                q.push({mid + 1, R, R - mid});
            } 
        }
        for (int i = 1; i <= N; i++) cout << a[i] << " ";cout << '\n'; 
    }
    return 0;
}