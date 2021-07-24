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

int f(int n)
{
 if (n <= 1)
  return 1;
 if (n & 1)
  return (f((n + 1) / 2) - 1) * 2;
 else
  return f(n / 2) * 2;
}

int main()
{
 setIO();
 int n;
 while (scanf("%d", &n), n)
  printf("%d\n", f(n));
 return 0;
}