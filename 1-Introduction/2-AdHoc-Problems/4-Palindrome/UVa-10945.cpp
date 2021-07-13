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
 string st;
 while (getline(cin, st) && st != "DONE")
 {
  string st1, st2;
  for (int i = 0; i < st.length(); i++)
   if (isalpha(st[i]))
    st1 += tolower(st[i]);
  st2 = st1;
  reverse(st1.begin(), st1.end());
  if (st1 == st2)
   cout << "You won't be eaten!"
        << "\n";
  else
   cout << "Uh oh.."
        << "\n";
 }
}
