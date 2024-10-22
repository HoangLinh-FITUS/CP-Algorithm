#include <iostream>
#include <set>
#include "D:\Education\CodeChecker\testlib.h"
//#include "testlib.h"

using namespace std;
const int N = 2e5 + 1;

int n, m;
set <pair<int,int>> S;

void read_input() {
    n = inf.readInt();
    m = inf.readInt();
    while (m--) {
        int u, v;
        u = inf.readInt();
        v = inf.readInt();
        S.insert({u, v});
    }
}

bool check(int cnt, int res[]) {
    for (int i = 0; i + 1 < cnt; i++) {
        if (S.find({res[i], res[i + 1]}) == S.end()) return false;
    }
    return true;
} 

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    read_input();
    string cnt_out = ouf.readString();
    string cnt_ans = ans.readString();
    if (cnt_out == cnt_ans && cnt_out == "IMPOSSIBLE") quitf(_ok, "ok");
    if (cnt_out != cnt_ans) quitf(_wa, "Độ dài chưa chính xác");

    int cnt = stoi(cnt_out);
    int *res = new int[cnt];
    for (int i = 0; i < cnt; i++) res[i] = ouf.readInt(1, n);
    if (!check(cnt, res)) quitf(_wa, "Đường đi không đúng");
    quitf(_ok, "ok");
}