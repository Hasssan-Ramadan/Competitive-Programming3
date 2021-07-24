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

char big[500][500], small[500][500];

int main()
{
 setIO();
 int n, m, i;
 while (scanf("%d %d", &n, &m) == 2)
 {
  if (n == 0 && m == 0)
   break;
  for (i = 0; i < n; i++)
   scanf("%s", big[i]);
  for (i = 0; i < m; i++)
   scanf("%s", small[i]);
  for (i = 0; i < 4; i++)
  {
   if (i)
    putchar(' ');
   int ans = 0, i, j, k, l;
   for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
     if (i + m <= n && j + m <= n)
     {
      int cnt = 0;
      for (k = 0; k < m; k++)
       for (l = 0; l < m; l++)
        if (big[i + k][j + l] == small[k][l])
         cnt++;
      if (cnt == m * m)
       ans++;
     }
   printf("%d", ans);
   char tmp[m][m];
   for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
     tmp[i][j] = small[m - j - 1][i];
   for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
     small[i][j] = tmp[i][j];
  }
  puts("");
 }
 return 0;
}
