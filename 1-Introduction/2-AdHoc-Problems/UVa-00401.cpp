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

static map<char, char> mirror;

bool isPalindrome(const string s)
{
 string ts = s;
 reverse(ts.begin(), ts.end());
 return s == ts;
}

bool isMirrorString(const string s)
{
 for (int i = 0, j = s.size() - 1; i < (s.size() + 1) / 2; ++i, --j)
  if (!mirror.count(s[i]) || mirror[s[i]] != s[j])
   return false;
 return true;
}

int main()
{
 vector<char> c = {'A', 'E', 'H', 'I', 'J', 'L', 'M', 'O', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '5', '8'};
 vector<char> mir = {'A', '3', 'H', 'I', 'L', 'J', 'M', 'O', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', 'Z', '8'};
 for (int i = 0; i < c.size(); ++i)
  mirror[c[i]] = mir[i];

 string s;
 while (cin >> s)
 {
  cout << s << " -- ";
  if (!isPalindrome(s) && !isMirrorString(s))
   cout << "is not a palindrome." << endl;
  else if (isPalindrome(s) && !isMirrorString(s))
   cout << "is a regular palindrome." << endl;
  else if (!isPalindrome(s) && isMirrorString(s))
   cout << "is a mirrored string." << endl;
  else
   cout << "is a mirrored palindrome." << endl;
  cout << endl;
 }
 return 0;
}