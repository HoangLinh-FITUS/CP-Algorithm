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

bool mid(Point p1, Point p2, Point p3) {
    return (min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) && 
            min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y));
}

int check(Point p1, Point p2, Point p3, Point p4) {
    if (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0) return true;
    if (ccw(p1, p2, p3) == 0 && mid(p1, p2, p3)) return true;
    if (ccw(p1, p2, p4) == 0 && mid(p1, p2, p4)) return true;
    if (ccw(p3, p4, p1) == 0 && mid(p3, p4, p1)) return true;
    if (ccw(p3, p4, p2) == 0 && mid(p3, p4, p2)) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        if (check(p1, p2, p3, p4)) cout << "YES\n"; 
        else cout << "NO\n";
    }
    return 0;
}