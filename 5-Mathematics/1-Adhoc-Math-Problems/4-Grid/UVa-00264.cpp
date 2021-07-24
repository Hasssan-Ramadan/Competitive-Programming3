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
 int n;
 while (scanf("%d", &n) == 1)
 {
  int line, sum = 0;
  for (int i = 1;; i++)
  {
   sum += i;
   if (sum >= n)
   {
    line = i;
    break;
   }
  }
  printf("TERM %d IS ", n);
  if (line % 2)
   printf("%d/%d\n", 1 + sum - n, line - (sum - n));
  else
   printf("%d/%d\n", line - (sum - n), 1 + sum - n);
 }
 return 0;
}