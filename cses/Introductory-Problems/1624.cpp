#include <iostream>
 
using namespace std;
 
char a[8][8];
 
bool cheotrai(int x,int y) {
    int i = x,j = y;
    while (i < 8 && j >= 0) {
        if (i != x && j != y && a[i][j] == 'x') return 0; 
        i++;
        j--;
    } 
    i = x,j = y;
    while (i >= 0 && j < 8) {
        if (i != x && j != y && a[i][j] == 'x') return 0; 
        i--;
        j++;
    } 
    return 1;
}
bool cheophai(int x,int y) {
    int i = x,j = y;
    while (i < 8 && j < 8) {
        if (i != x && j != y && a[i][j] == 'x') return 0; 
        i++;
        j++;
    } 
    i = x,j = y;
    while (i >= 0 && j >= 0) {
        if (i != x && j != y && a[i][j] == 'x') return 0; 
        i--;
        j--;
    } 
    return 1;
}
bool doc(int x,int y) {
    for(int i = 0; i < 8; i++) if (i != x) {
        if (a[i][y] == 'x') return 0;
    }
    return 1;
}
bool ngang(int x,int y) {
    for(int i = 0; i < 8; i++) if (i != y) {
        if (a[x][i] == 'x') return 0;
    }
    return 1;
}
bool check() {
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) if (a[x][y] == 'x') {
            if (!doc(x,y) || !ngang(x,y) || !cheophai(x,y) || !cheotrai(x,y)) return 0;
        }
    }
    return 1;
}
 
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) cin >> a[i][j];
    }
    int res = 0;
    for(int i1 = 0; i1 < 8; i1++) if (a[0][i1] != '*') 
    for(int i2 = 0; i2 < 8; i2++) if (a[1][i2] != '*')
    for(int i3 = 0; i3 < 8; i3++) if (a[2][i3] != '*')
    for(int i4 = 0; i4 < 8; i4++) if (a[3][i4] != '*')
    for(int i5 = 0; i5 < 8; i5++) if (a[4][i5] != '*')
    for(int i6 = 0; i6 < 8; i6++) if (a[5][i6] != '*')
    for(int i7 = 0; i7 < 8; i7++) if (a[6][i7] != '*')
    for(int i8 = 0; i8 < 8; i8++) if (a[7][i8] != '*') {
        a[0][i1] = 'x';a[1][i2] = 'x';a[2][i3] = 'x';
        a[3][i4] = 'x';a[4][i5] = 'x';a[5][i6] = 'x';a[6][i7] = 'x';a[7][i8] = 'x';
        res += check();
        a[0][i1] = '.';a[1][i2] = '.';a[2][i3] = '.';
        a[3][i4] = '.';a[4][i5] = '.';a[5][i6] = '.';a[6][i7] = '.';a[7][i8] = '.';
    }
    cout << res;
    return 0;
}