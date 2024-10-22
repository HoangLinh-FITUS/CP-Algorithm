#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int i = n + 1;
    while (1) {
        int j = 1;
        while (j <= n && __gcd(i,j) == 1) j++;
        if (j > n) return cout << i,0;
        i++;
    }
    return 0;
}