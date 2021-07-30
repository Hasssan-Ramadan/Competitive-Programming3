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
 int t;
 scanf("%d", &t);
 getchar();
 getchar();
 while (t--)
 {
  map<string, int> record;
  string tree;
  int n = 0;
  while (getline(cin, tree))
  {
   if (tree.compare("") == 0)
    break;
   record[tree]++;
   n++;
  }
  for (map<string, int>::iterator i = record.begin(); i != record.end(); i++)
   cout << i->first << " " << fixed << setprecision(4) << i->second * 100.0 / n << endl;
  if (t)
   puts("");
 }
 return 0;
}
