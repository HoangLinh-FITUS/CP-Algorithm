// chua toi uu 
#include <iostream>
#include <cstring>

using namespace std;

int memories[50][10][10];
int dd[10][10];

bool insideBoard(int x, int y) {
    return 1 <= x && x <= 7 && 1 <= y && y <= 7;
}


pair <int, int> direction(int x, int y, char s) {
    if (s == 'L' && insideBoard(x, y - 1)) return {0, -1};
    if (s == 'R' && insideBoard(x, y + 1)) return {0, 1};
    if (s == 'U' && insideBoard(x - 1, y)) return {-1, 0};
    if (s == 'D' && insideBoard(x + 1, y)) return {1, 0};
    return {0, 0};
}


int dp(string &st, int i, int x = 1, int y = 1) {
    if (dd[x][y] == 1) return 0;
    
    if (i == st.size()) {
        return (x == 7 && y == 1);
    }

    //int &res = memories[i][x][y];
    //if (res != -1) return res;
    int res = 0;
    pair <int, int> dic = direction(x, y, st[i]);
    dd[x][y] = 1;
    if (st[i] != '?') {
        if (dic.first + dic.second != 0) {
            res += dp(st, i + 1, x + dic.first, y + dic.second);
        }
    }
    else {
        for (char d: {'L', 'R', 'U', 'D'}) {
            dic = direction(x, y, d);
            if (dic.first + dic.second == 0) continue; 
            res += dp(st, i + 1, x + dic.first, y + dic.second);
        }
    }
    dd[x][y] = 0;
    return res;
}

int main() {
    string st = "??????????????????UL????U?L??L?D???RR???????????";
    cin >> st;
    memset(memories, -1, sizeof(memories));
    cout << dp(st, 0) << '\n';
    return 0;
}