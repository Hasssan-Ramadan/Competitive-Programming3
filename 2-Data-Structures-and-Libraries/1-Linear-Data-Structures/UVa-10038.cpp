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
 int n, A[3001], i;
 while (scanf("%d", &n) == 1)
 {
  for (i = 0; i < n; i++)
   scanf("%d", &A[i]);
  int mark[3001] = {0}, flag = 0;
  for (i = 1; i < n; i++)
  {
   if (abs(A[i] - A[i - 1]) < n)
    mark[abs(A[i] - A[i - 1])]++;
  }
  for (i = 1; i < n; i++)
   if (mark[i] == 0)
    flag = 1;
  if (flag)
   puts("Not jolly");
  else
   puts("Jolly");
 }
 return 0;
}