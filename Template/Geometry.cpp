#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

#define LSOne(S) (S & (-S))

#define EPS 1e-9

// get distance between two points
double distance(double x1, double y1, double x2, double y2)
{
 return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// check if triangle is valid using its sides
bool isValidTriangle(double a, double b, double c)
{
 return a + b > c && a + c > b && b + c > a;
}

// check if a single straight line can pass through these three points
bool isValidLine(double x1, double y1, double x2, double y2, double x3, double y3)
{
 return (x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2) == 0;
}

// get area of triangle using its sides
double area(double a, double b, double c)
{
 double s = (a + b + c) / 2;
 return sqrt(s * (s - a) * (s - b) * (s - c));
}

// check if point belongs to circle of radius r and center at (cx, cy)
// formula of circle: (x - cx)^2 + (y - cy)^2 = r^2
bool isInsideCircle(double x, double y, double r, double cx, double cy)
{
 return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}

// check if two circles intersect
bool circleIntersect(double x1, double y1, double r1, double x2, double y2, double r2)
{
 return distance(x1, y1, x2, y2) <= r1 + r2;
}

// check if the given point is inside the given rectangle
bool isInsideRectangle(double x, double y, double x1, double y1, double x2, double y2)
{
 return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}