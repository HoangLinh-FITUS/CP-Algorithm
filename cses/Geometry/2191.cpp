#include <iostream>

using namespace std;
#define Point pair <long long, long long>
#define x first 
#define y second 

Point operator + (Point A, Point B) {return Point(A.x + B.x, A.y + B.y); }
Point operator - (Point A, Point B) {return Point(A.x - B.x, A.y - B.y); }
double operator ^ (Point A, Point B) {return A.x * B.x + A.y * B.y; }
long long operator * (Point A, Point B) {return A.x * B.y - A.y * B.x; }

int ccw(Point A, Point B, Point C) {
    long long c = (B - A) * (C - A);
    if (c > 0) return 1;
    if (c < 0) return -1;
    return 0;
}

int n;
Point a[10001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    a[n + 1] = a[1];
    long long res = 0;
    for (int i = 1; i <= n; i++) res += a[i] * a[i + 1];
    cout << abs(res);
    return 0;
}