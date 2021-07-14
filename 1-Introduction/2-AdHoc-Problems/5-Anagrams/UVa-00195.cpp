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

bool stringComp(char a, char b)
{
 if (tolower(a) == tolower(b))
  return a < b;
 return tolower(a) < tolower(b);
}

int main()
{
 setIO();
 string st;
 int t;
 cin >> t;
 while (t--)
 {
  cin >> st;
  sort(all(st), stringComp);
  do
  {
   cout << st << "\n";
  } while (next_permutation(all(st), stringComp));
 }
}
