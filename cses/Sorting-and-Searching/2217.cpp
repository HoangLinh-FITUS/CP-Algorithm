#include <iostream>

using namespace std;
const int N = 2e5 + 1;

int n, m;
int a[N], pos[N];

int change(int Min, int Max, int add) {
    int total = 0;
    if (pos[Min - 1] > pos[Min]) total += add;
    if (pos[Max - 1] > pos[Max]) total += add;
    if (Min + 1 != Max && pos[Min] > pos[Min + 1]) total += add;
    if (pos[Max] > pos[Max + 1]) total += add;
    return total;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int res = 1;
    a[0] = -1;
    for (int i = 1; i <= n; i++) res += pos[i - 1] > pos[i];

    while (m--) {
        int posA, posB;
        cin >> posA >> posB;
        int Min = min(a[posA], a[posB]);
        int Max = max(a[posA], a[posB]);

        res += change(Min, Max, -1);

        swap(a[posA], a[posB]);
        pos[a[posA]] = posA;
        pos[a[posB]] = posB;

        res += change(Min, Max, 1);
        cout << res << '\n';
    }
    return 0;
}