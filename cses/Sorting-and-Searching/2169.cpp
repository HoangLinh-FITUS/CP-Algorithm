#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 4e5 + 10;

struct Time {
    int Start, End, pos;
    bool operator < (const Time &other) const { 
        if (Start == other.Start) return End > other.End;
        return Start < other.Start;
    }
} T[N];

int n;
int BIT[N], itContains[N], containIt[N];

void update(int x) {
    for (; x < N; x += x & -x) BIT[x]++;
}

int get(int x) {
    int cnt = 0;
    for (; x; x -= x & -x) cnt += BIT[x];
    return cnt;
}

void compressionTime() {
    vector <int> com;
    for (int i = 1; i <= n; i++) {
        com.push_back(T[i].Start);
        com.push_back(T[i].End);
    }   

    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());

    for (int i = 1; i <= n; i++) {
        T[i].Start = lower_bound(com.begin(), com.end(), T[i].Start) - com.begin() + 2;
        T[i].End = lower_bound(com.begin(), com.end(), T[i].End) - com.begin() + 2;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> T[i].Start >> T[i].End, T[i].pos = i;

    sort(T + 1, T + n + 1);
    compressionTime();

    for (int i = n; i >= 1; i--) {
        itContains[T[i].pos] = get(T[i].End);
        update(T[i].End);
    } 

    for (int i = 1; i < N; i++) BIT[i] = 0;
    for (int i = 1; i <= n; i++) {
        containIt[T[i].pos] = i - 1 - get(T[i].End - 1);
        update(T[i].End);
    }

    for (int i = 1; i <= n; i++) cout << itContains[i] << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << containIt[i] << " ";

    return 0;
}