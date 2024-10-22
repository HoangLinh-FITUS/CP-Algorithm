#include <iostream>
#include <string.h>

using namespace std;

int me[501][501];

int calc(int a,int b) {
    if (a == b) return 0;
    int& res = me[a][b];
    if (res) return res;
    res = 1e9;
    // cat hang 
    for(int i = 1; i < a; i++) res = min(res,calc(i,b) + calc(a - i,b) + 1);
    // cat cot 
    for(int i = 1; i < b; i++) res = min(res,calc(a,i) + calc(a,b - i) + 1); 
    me[b][a] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int a,b;
    cin >> a >> b;
    cout << calc(a,b);
    return 0;
}