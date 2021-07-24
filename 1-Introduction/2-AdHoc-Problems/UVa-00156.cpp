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
 string s;
 multimap<string, string> memo;
 while (cin >> s, s != "#")
 {
  string t(s);
  transform(s.begin(), s.end(), t.begin(), ::tolower);
  sort(t.begin(), t.end());
  memo.insert(pair<string, string>(t, s));
 }
 multimap<string, string>::iterator iter(memo.begin());
 vector<string> ananagrams;
 for (; iter != memo.end(); ++iter)
  if (memo.count(iter->first) == 1)
   ananagrams.push_back(iter->second);
 sort(ananagrams.begin(), ananagrams.end());
 for (auto el : ananagrams)
  cout << el << "\n";
 return 0;
}