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

int calcSum(int n)
{
 int sum = 0;
 for (int i = 1; i <= n / 2; i++)
  if (n % i == 0)
   sum += i;
 return sum;
}

int main()
{
 setIO();
 cout << "PERFECTION OUTPUT" << endl;
 int n;
 while (cin >> n, n)
 {
  int sum = calcSum(n);
  cout << setw(5) << n << "  ";
  if (sum == n)
   cout << "PERFECT";
  else if (sum < n)
   cout << "DEFICIENT";
  else if (sum > n)
   cout << "ABUNDANT";
  cout << endl;
 }
 cout << "END OF OUTPUT" << endl;
}
