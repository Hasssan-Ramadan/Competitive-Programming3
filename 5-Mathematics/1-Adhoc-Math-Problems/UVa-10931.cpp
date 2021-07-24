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

int n, cnt, it;
bool a[35];

void bin(int n)
{
 cnt = 0;
 it = 0;
 while (n)
 {
  if (n % 2)
   cnt++, a[it++] = 1;
  else
   a[it++] = 0;
  n /= 2;
 }
}

int main()
{
 setIO();
 while (scanf("%d", &n), n)
 {
  bin(n);
  printf("The parity of ");
  for (int i = it - 1; i >= 0; i--)
   printf("%d", a[i]);
  printf(" is %d (mod 2).\n", cnt);
 }
}
