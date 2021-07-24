#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "")
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 if (sz(name))
 {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
 }
}

int main()
{
 setIO();
 char dot;
 double minute, hour, angle, hourAng, minuteAng;
 while (cin >> hour >> dot >> minute, hour != 0 || minute != 0)
 {
  hourAng = hour * 30 + (minute / 60) * 30;
  minuteAng = minute * 6;
  angle = hourAng - minuteAng;
  angle *= angle < 0 ? -1 : 1;
  angle = angle > 180 ? 360 - angle : angle;
  printf("%.3f\n", angle);
 }
}