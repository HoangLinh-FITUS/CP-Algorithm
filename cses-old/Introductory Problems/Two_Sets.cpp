#include <iostream>
#include <vector>

using namespace std;

void calc(int i,int j,vector <int> &res) {
    while (i <= j) {
        res.push_back(i);
        res.push_back(j);
        i += 2;
        j -= 2;
    }
    cout << res.size() << '\n';
    for(auto &i: res) cout << i << " ";cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    if (n % 4 != 0 && (n + 1) % 4 != 0) return cout << "NO",0;
    cout << "YES\n";

    vector <int> res;
    if (n & 1) res.push_back(n--);
    calc(2,n - 1,res);
    res.clear();
    calc(1,n,res);
    return 0;
}