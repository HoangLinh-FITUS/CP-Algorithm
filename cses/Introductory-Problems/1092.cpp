#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> lst1, lst2;

int main() {
    cin >> n;
    
    if (n * (n + 1) % 4) return cout << "NO", 0;
    cout << "YES\n";
    // 1 2 3 4 5 6 7 
    // 7 5 2 
    // 6 1 3 4 

    if (n & 1) lst1 = {n--};
    for (int i = 1; i <= n / 2; i++) {
        if (i & 1) {
            lst2.push_back(i);
            lst2.push_back(n - i + 1);
        } else {
            lst1.push_back(i);
            lst1.push_back(n - i + 1);
        }
    }
    
    cout << lst1.size() << '\n'; for (auto i: lst1) cout << i << " ";cout << '\n';
    cout << lst2.size() << '\n'; for (auto i: lst2) cout << i << " ";cout << '\n';
    return 0;
}