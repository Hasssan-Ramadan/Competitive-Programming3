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
 int t;
 scanf("%d", &t);
 while (t--)
 {
  int m, n;
  char c;
  scanf(" %c %d %d", &c, &m, &n);
  if (c == 'r' || c == 'Q')
  {
   printf("%d\n", min(m, n));
  }
  else if (c == 'k')
  {
   printf("%d\n", m * n / 2);
  }
  else if (c == 'K')
   printf("%d\n", ((m + 1) / 2) * ((n + 1) / 2));
 }
}
