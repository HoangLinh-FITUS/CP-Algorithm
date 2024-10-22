#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 

using namespace std;
 
#define Point pair<int,int>
#define x first 
#define y second 
 
Point operator + (Point A,Point B) {return Point(A.x + B.x,A.y + B.y);}
Point operator - (Point A,Point B) {return Point(A.x - B.x,A.y - B.y);}
double operator ^ (Point A,Point B) {return A.x * B.x + A.y * B.y;}
double operator * (Point A,Point B) {return A.x * B.y - A.y * B.x;}
 
int ccw(Point A,Point B,Point C) {
    double t = (B - A) * (C - B);
    if (t > 0) return 1;
    if (t < 0) return -1;
    return 0;
}
 
ostream& operator << (ostream &os, Point &a) {
    os << "(" << a.x << "," << a.y << ")";
    return os;
}
 
Point a[(int)2e5 + 1];
int n;
 
int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
 
    sort(a + 1,a + n + 1);
    vector <Point> q;
    for(int i = 1; i <= n; i++) {
        while (q.size() >= 2 && ccw(q[q.size() - 2],q.back(),a[i]) < 0) q.pop_back(); 
        q.push_back(a[i]);
    }
    Point* res = new Point[n];
    int m = 0;
    for(auto &i: q) res[m++] = i; 
    q.clear();
    for(int i = n; i >= 1; i--) {
        while (q.size() >= 2 && ccw(q[q.size() - 2],q.back(),a[i]) < 0) q.pop_back();
        q.push_back(a[i]);
    }
    for(int i = 1; i < (int)q.size() - 1; i++) res[m++] = q[i];
    cout << m << '\n';
    for(int i = 0; i < m; i++) cout << res[i].x << " " << res[i].y << '\n';
    return 0;
}