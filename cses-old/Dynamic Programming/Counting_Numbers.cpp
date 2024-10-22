#include <iostream>
#include <cstring>
#define int long long 

using namespace std;

int me[19][19][2][2];

int calc(int i,int pre,bool ok,bool check,const string &s) {
    if (i == s.size()) return 1;
    int c = ok ? s[i] - '0' : 9;
    int& res = me[i][pre][ok][check];
    if (res != -1) return res;
    res = 0;
    for(int j = 0; j <= c; j++) {
        if (check == 0 && j == pre) continue; 
        res += calc(i + 1,j,ok & (j == s[i] - '0'),check & !j,s);
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    long long x,y;
    cin >> x >> y;
    memset(me,-1,sizeof(me));
    int s2 = calc(0,0,1,1,to_string(y));
    if (x == 0) cout << s2;
    else {
        memset(me,-1,sizeof(me));
        int s1 = calc(0,0,1,1,to_string(x - 1));
        cout << s2 - s1;
    } 
    
    return 0;
}