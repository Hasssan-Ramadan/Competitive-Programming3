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
#define PI 3.14159265358979323846

// get distance between two points
double calcDistance(double x1, double y1, double x2, double y2)
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
double getTriangleArea(double a, double b, double c)
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
 return calcDistance(x1, y1, x2, y2) <= r1 + r2;
}

// check if the given point is inside the given rectangle
bool isInsideRectangle(double x, double y, double x1, double y1, double x2, double y2)
{
 return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

// check if triangle is right angled
bool isRightAngled(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
 ll A = (ll)pow((x2 - x1), 2) + (ll)pow((y2 - y1), 2);
 ll B = (ll)pow((x3 - x2), 2) + (ll)pow((y3 - y2), 2);
 ll C = (ll)pow((x3 - x1), 2) + (ll)pow((y3 - y1), 2);
 return ((A > 0 and B > 0 and C > 0) and (A == (B + C) or B == (A + C) or C == (A + B)));
}

// get the area of the rectangle (tr -> top-right, bl -> bottom-left)
ll getRectArea(ll bl_x, ll bl_y, ll tr_x, ll tr_y)
{
 ll length = tr_y - bl_y;
 ll width = tr_x - bl_x;
 return length * width;
}

// checks if two rectangles intersect
bool isRectsIntersect(vector<ll> s1, vector<ll> s2)
{
 ll bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
 ll bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

 if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y || tr_a_y <= bl_b_y)
  return false;
 else
  return true;
}

// get intersect area between two rectangles (same technique in case of multiple rects)
ll getRectsIntersectArea(vector<ll> s1, vector<ll> s2)
{
 ll bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
 ll bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

 return (max(min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x), 0LL) * max(min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y), 0LL));
}

// get the area of circumscribed circle of regular polygon
// circumscribed circle of a polygon is the circle that passes through all the vertices of that polygon.
double getCircumscribedCircleArea(ll side, ll numOfSides)
{
 double r = (side) / (2 * sin(PI / numOfSides));
 return PI * r * r;
}

// get area of square drawn inside circle
double getSquareInCircleArea(double radius)
{
 return 2 * radius * radius;
}