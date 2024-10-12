#include <iostream>

using namespace std;
#define Point pair <long long, long long>
#define x first 
#define y second 

Point operator + (Point A, Point B) {return Point(A.x + B.x, A.y + B.y); }
Point operator - (Point A, Point B) {return Point(A.x - B.x, A.y - B.y); }
double operator ^ (Point A, Point B) {return A.x * B.x + A.y * B.y; }
double operator * (Point A, Point B) {return A.x * B.y - A.y * B.x; }

int ccw(Point A, Point B, Point C) {
    long long c = (B - A) * (C - A);
    if (c > 0) return 1;
    if (c < 0) return -1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Point p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        if (ccw(p1, p2, p3) > 0) cout << "LEFT\n";
        else if (ccw(p1, p2, p3) < 0) cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }
    return 0;
}