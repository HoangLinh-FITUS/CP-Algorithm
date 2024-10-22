#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string TestPath,CurrPath,Input,Output,Answer;
ifstream in,out,ans;

void init() {
    getline(cin,TestPath);
    getline(cin,CurrPath);
    Input = TestPath + "RCSCONVC.INP";
    Answer = TestPath + "RCSCONVC.OUT";
    Output = CurrPath + "RCSCONVC.OUT";
    in.open(Input);
    out.open(Output);
    ans.open(Answer);
}

#define KQsai return cout << "Ket qua sai! \n" << 0.0,0
#define KQdung return cout << "Ket qua dung! \n" << 1.0,0

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    init();
    int a,b;
    in >> a >> b;
    string YN_ans,YN_out;
    getline(ans,YN_ans);
    getline(out,YN_out);
    if (YN_ans != YN_out) KQsai;
    if (YN_ans == "NO") KQdung;
    int cnt_ans(0),cnt_out(0);
    ans >> cnt_ans;
    out >> cnt_out;

    if (cnt_out != cnt_ans) KQsai;

    int n = cnt_out;
    vector <int> x(n + 1,0);
    for(int i = 1; i <= n; i++) out >> x[i];
    if (x[1] != a || x[n] != b) KQsai;
    for(int i = 2; i <= n; i++) {
        if (x[i - 1] * 2 == x[i] || x[i - 1] * 10 + 1 == x[i]) continue;
        KQsai;
    }
    KQdung;
    return 0;
}
