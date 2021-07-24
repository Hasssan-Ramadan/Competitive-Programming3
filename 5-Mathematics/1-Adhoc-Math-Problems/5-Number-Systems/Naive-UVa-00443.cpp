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
 vector<ll> humbleNums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27};
 ll h = 27, temp;
 while (true)
 {
  h++;
  temp = h;
  while (temp % 2 == 0)
   temp /= 2;
  while (temp % 3 == 0)
   temp /= 3;
  while (temp % 5 == 0)
   temp /= 5;
  while (temp % 7 == 0)
   temp /= 7;
  if (temp == 1)
  {
   humbleNums.push_back(h);
  }
  if (humbleNums.size() == 5843)
   break;
 }
 int n;
 while (cin >> n, n)
 {
  string st;
  if (n % 10 == 1 && n % 100 != 1)
   st = "st";
  else if (n % 10 == 2 && n % 100 != 1)
   st = "nd";
  else if (n % 10 == 3 && n % 100 != 1)
   st = "rd";
  else
   st = "th";
  cout << "The " << n << st << " humble number is " << humbleNums[n - 1] << ".";
 }
}
