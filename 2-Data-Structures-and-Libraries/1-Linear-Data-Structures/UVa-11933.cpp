#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;

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
 ui num;
 while (scanf("%u", &num), num)
 {
  ui a = 0, b = 0, toAdd = 1;
  bool addToA = true;
  while (num)
  {
   if (num & 1)
   {
    if (addToA)
     a += toAdd;
    else
     b += toAdd;
    addToA = !addToA;
   }
   toAdd *= 2;
   num /= 2;
  }
  printf("%u %u\n", a, b);
 }
}
