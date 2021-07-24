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

#define MAX 5842
ll HN[MAX + 10];

void generateHumbleNumbers(void)
{
 HN[1] = 1;
 int j = 2;
 int w = 1, x = 1, y = 1, z = 1;
 for (long long i = 2; i <= MAX; i++)
 {
  HN[i] = min(min(2 * HN[w], 3 * HN[x]), min(5 * HN[y], 7 * HN[z]));
  if (HN[i] == 2 * HN[w])
   w++;
  if (HN[i] == 3 * HN[x])
   x++;
  if (HN[i] == 5 * HN[y])
   y++;
  if (HN[i] == 7 * HN[z])
   z++;
 }
}

int main()
{
 setIO();
 generateHumbleNumbers();
 int n;
 while (cin >> n, n)
 {
  string st;
  if (n % 10 == 1 && n % 100 != 11)
   st = "st";
  else if (n % 10 == 2 && n % 100 != 12)
   st = "nd";
  else if (n % 10 == 3 && n % 100 != 13)
   st = "rd";
  else
   st = "th";
  cout << "The " << n << st << " humble number is " << HN[n] << ".\n";
 }
}
