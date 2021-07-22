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
 list<char> lst;
 list<char>::iterator it;
 while (getline(cin, st))
 {
  lst.clear();
  it = lst.begin();
  for (int i = 0; i < st.size(); ++i)
  {
   if (st[i] == '[')
    it = lst.begin();
   else if (st[i] == ']')
    it = lst.end();
   else if (st[i] != '[' && st[i] != ']')
    lst.insert(it, st[i]);
  }
  for (auto c : lst)
   printf("%c", c);
  printf("\n");
 }
 return 0;
}
