#define taskname "SUM"
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long lli;
const int maxN = 101;
const lli Radix = 1e15;
const int gd = 15;

class TNumber: public vector<lli>
{
#define self (*this)
public:
    void Refine()
    {
        while (!empty() && back() == 0) pop_back();
    }
    TNumber& operator = (lli x)
    {
        clear();
        for (; x > 0; x /= Radix)
            push_back(x % Radix);
        return self;
    }
    TNumber operator + (const TNumber& other) const
    {
        TNumber res;
        res.resize(max(size(), other.size()), 0);
        lli carry = 0;
        for (int i = 0; i < (int)res.size(); ++i)
        {
            if (i < (int)size()) carry += self[i];
            if (i < (int)other.size()) carry += other[i];
            res[i] = carry % Radix;
            carry /= Radix;
        }
        if (carry > 0)
            res.push_back(carry);
        return res;
    }
    TNumber operator * (lli x) const
    {
        TNumber res;
        lli carry = 0;
        for (int i = 0; i < (int)size(); ++i)
        {
            carry += self[i] * x;
            res.push_back(carry % Radix);
            carry /= Radix;
        }
        for (; carry > 0; carry /= Radix)
            res.push_back(carry % Radix);
        return res;
    }
    void Print() const
    {
        if (empty()) cout << '0';
        else
        {
            cout << back();
            for (int i = size() - 2; i >= 0; --i)
                cout << setw(gd) << setfill('0') << self[i];
        }
    }
};

string st;
lli x[maxN];
int n;
TNumber f[maxN], g[maxN], h[maxN];
int s[10];

void ReadInput()
{
    getline(cin, st);
    n = (int)st.length();
    for (int i = 0; i < n; ++i)
        x[i] = st[n - 1 - i] - '0';
}

void Init()
{
    //f[i] = số dãy có i chữ số
    //g[i] = tổng các chữ số của các dãy có i chữ số
    f[0] = 1;
    for (int i = 1; i < n; ++i)
        f[i] = f[i - 1] * 10;
    g[0] = 0;
    for (int i = 1; i < n; ++i)
        g[i] = f[i - 1] * (45 * i); //chữ số d ở một vị trí j được cộng vào g[i] đúng f[i - 1] lần
    //h[i]: số dãy y[n - 1...0] < x mà y[n - 1...i] = x[n - 1...i]
    //h[i] = số biểu diễn bởi x[i - 1...0]
    h[0] = 0;
    TNumber P10;
    P10 = 1;
    for (int i = 1; i < n; ++i)
    {
        h[i] = h[i - 1] + P10 * x[i - 1];
        P10 = P10 * 10;
    }
    //s[i] = tổng các chữ số từ 0 tới i
    s[0] = 0;
    for (int i = 1; i <= 9; ++i)
        s[i] = s[i - 1] + i;
}

void Solve()
{
    TNumber res;
    lli temp = 0;
    for (int i = 0; i < n; ++i)
        temp += x[i];
    res = temp;
    for (int i = n - 1; i >= 0; --i)
    {
        if (x[i] > 0)
            res = res + f[i] * s[x[i] - 1] + g[i] * x[i];
        res = res + h[i] * x[i];
    }
    res.Print();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Init();
    Solve();
}
