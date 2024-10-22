#include <bits/stdc++.h>

using namespace std;

#define el '\n'

string x, y;
vector<int> f[10];

void init() {	// cài đặt trước chu kì của các số.
  for (int i = 0; i < 10; ++i) {
    f[i].push_back(i);
    int p = i;
    while (((p *= i) %= 10) != i) f[i].push_back(p);
  }
}

int operator % (string a, int b) {	// chia lấy dư của một số lớn cho một số nhỏ.
  int res = 0;
  for (char d : a) res = (res * 10 + d - '0') % b;
  return res;
}

int res(int a, string b_) {	// tìm vị trí của trong chu kì và trả về kết quả.
  int b = b_ % f[a].size();
  b = (b == 0 ? f[a].size() - 1 : b-1);
  return f[a][b];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  cin >> x >> y;
  cout << res(x.back() - '0', y);	// chỉ lấy giá trị cuối cùng của x và lấy giá trị của y.
  return 0;
}
