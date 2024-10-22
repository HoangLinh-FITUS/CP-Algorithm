#include <iostream>
#include <string.h>
#define cout cerr

#define int long long 
using namespace std;

int me[8][8][50];
string st;
bool dd[8][8];

bool inside_board(int i,int j) {
    return 0 <= i && i < 7 && 0 <= j && j < 7;
}

int Try(int i,int j,int k,string s = "") {
    if (!inside_board(i,j)) return 0;
    if (dd[i][j]) return 0;
    cout << s << '\n';
    for(int i = 0; i < 7; i++) {
            for(int j = 0; j < 7; j++) cout << dd[i][j] << " ";
            cout << '\n';
        }
        cout << "=====\n";
    if (k == st.size()) {
        for(int i = 0; i < 7; i++) {
            for(int j = 0; j < 7; j++) cout << dd[i][j] << " ";
            cout << '\n';
        }
        cout << "=====\n";
        exit(0);

        return 1;
    }
    int &res = me[i][j][k];
    if (res != 0) return res;
    res = 0;

    dd[i][j] = 1;
    if (st[k] == 'U') res += Try(i - 1,j,k + 1,s + "U");
    else if (st[k] == 'D') res += Try(i + 1,j,k + 1,s + "D");
    else if (st[k] == 'L') res += Try(i,j - 1,k + 1,s + "L");
    else if (st[k] == 'R') res += Try(i,j + 1,k + 1,s + "R");
    else if (st[k] == '?') {
        res += Try(i - 1,j,k + 1,s + "U");
        res += Try(i,j + 1,k + 1,s + "R");
        res += Try(i + 1,j,k + 1,s + "D");
        res += Try(i,j - 1,k + 1,s + "L");
    }
    dd[i][j] = 0;
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> st;
    cout << Try(0,0,0);
    return 0;
}