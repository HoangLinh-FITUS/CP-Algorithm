#include <iostream>
#include <algorithm>

using namespace std;
const int N = (int)1e6 + 1;

int times = 0;
int trie[N][26],endstr[N];

void insert(const string &s) {
    int u = 0;
    for(const auto &v: s) {
        int &x = trie[u][v - 'a'];
        if (!x) x = ++times; 
        u = x;
    }
    endstr[u] = 1;
}

string str;
int dp[N];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int q;
    cin >> str >> q;
    while (q--) {
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        insert(s);
    }

    dp[0] = 1;
    int n = str.size();
    for(int i = 1; i <= n; i++) {
        int j = i,u = 0;
        while (trie[u][str[j - 1] - 'a']) {
            u = trie[u][str[j - 1] - 'a'];
            if (endstr[u] == 1) {
                dp[i] += dp[j - 1];
                if (dp[i] >= 1000000007) dp[i] -= 1000000007;
            }
            j--;
        }
    }
    cout << dp[n];

    return 0;
}