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
 int n, m, d, k;
 vector<vi> v;
 while (scanf("%d %d", &n, &m) != EOF)
 {
  v.assign(1000000, vi());
  for (int i = 1; i <= n; i++)
  {
   scanf("%d", &d);
   v[d].pb(i);
  }
  for (int i = 0; i < m; i++)
  {
   scanf("%d %d", &k, &d);
   if (k - 1 < sz(v[d]))
    printf("%d\n", v[d][k - 1]);
   else
    printf("0\n");
  }
 }
 return 0;
}
