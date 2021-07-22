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
 int laps, l, m, c, car, load;
 string bank;
 bool rightBank;
 cin >> c;
 for (int i = 0; i < c; i++)
 {
  cin >> l >> m;
  queue<int> Left, Right;
  load = rightBank = 0;
  for (int j = 0; j < m; j++)
  {
   cin >> car >> bank;
   bank == "left" ? Left.push(car) : Right.push(car);
  }
  laps = 0;
  l *= 100;
  while (!Left.empty() || !Right.empty())
  {
   load = 0;
   if (rightBank)
   {
    while (!Right.empty() && load + Right.front() <= l)
    {
     load += Right.front();
     Right.pop();
    }
   }
   else
   {
    while (!Left.empty() && load + Left.front() <= l)
    {
     load += Left.front();
     Left.pop();
    }
   }
   ++laps;
   rightBank = 1 - rightBank;
  }
  cout << laps << endl;
 }
 return 0;
}