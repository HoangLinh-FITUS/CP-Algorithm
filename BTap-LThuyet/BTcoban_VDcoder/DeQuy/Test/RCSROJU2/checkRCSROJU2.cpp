#include <iostream>
#include <fstream>
#include <vector>
#define TASK "RCSROJU2"

using namespace std;

string TestPath = "",CurrPath = "",Input,Output,Answer;
ifstream in,out,ans;

void init() {
    getline(cin,TestPath);
    getline(cin,CurrPath);
    Input = TestPath + TASK + ".INP";
    Answer = TestPath + TASK + ".OUT";
    Output = CurrPath + TASK + ".OUT";
    in.open(Input);
    out.open(Output);
    ans.open(Answer);
}

void CloseFile() {
    in.close();
    out.close();
    ans.close();
}

#define KQsai return cout << "Ket qua sai! \n" << 0.0,0
#define KQdung return cout << "Ket qua dung! \n" << 1.0,0

int n,m;
int sx,sy,tx,ty;
char a[1000][1000];
int dd[1000][1000];

bool inside(int x,int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m && dd[x][y] == 1;
}

void dfs(int x,int y) {
    dd[x][y] = 2;
    if (inside(x + 1,y)) dfs(x + 1,y);
    if (inside(x - 1,y)) dfs(x - 1,y);
    if (inside(x,y + 1)) dfs(x,y + 1);
    if (inside(x,y - 1)) dfs(x,y - 1);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    init();
    in >> n >> m;
    string YN_ans,YN_out;
    getline(ans,YN_ans);
    getline(out,YN_out);
    if (YN_ans != YN_out) KQsai;
    if (YN_ans == "NO") KQdung;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) in >> a[i][j];
    }
    vector <pair<int,int>> path;
    int T;
    out >> T;
    while (T--) {
        int x,y;
        out >> x >> y;
        path.push_back({x,y});
        if (a[x][y] == 'x') KQsai;
        dd[x][y] = 1;
    }
    if (a[path[0].first][path[0].second] != 'R') KQsai;
    if (a[path.back().first][path.back().second] != 'J') KQsai;
    dfs(path[0].first,path[0].second);
    if (dd[path.back().first][path.back().second] == 2) KQdung;
    KQsai;
    CloseFile();
    return 0;
}
