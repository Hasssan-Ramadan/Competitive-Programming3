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

int calNum(int m, int n)
{
  if (n < m)
    swap(n, m);
  if (m == 1)
    return n;
  else if (m == 2)
    return 4 * (n / 4) + 2 * min(2, n % 4);
  else
    return (m * n + 1) / 2;
}

int main()
{
  setIO();
  int m, n;
  while (scanf("%d %d", &m, &n), m + n)
  {
    printf("%d knights may be placed on a %d row %d column board.\n", calNum(m, n), m, n);
  }
  return 0;
}