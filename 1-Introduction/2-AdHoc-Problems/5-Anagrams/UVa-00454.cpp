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

string getSortedChars(const string st)
{
  string bs(st);
  bs.erase(remove(bs.begin(), bs.end(), ' '), bs.end());
  sort(bs.begin(), bs.end());
  return bs;
}

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
  cin >> t;
  cin.ignore();
  cin.ignore();
  while (t--)
  {
    string s;
    vector<string> words;
    while (getline(cin, s) && s != "")
      words.push_back(s);
    sort(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++)
      for (int j = i + 1; j < words.size(); j++)
        if (getSortedChars(words[i]) == getSortedChars(words[j]))
          cout << words[i] << " = " << words[j] << endl;
    if (t)
      cout << endl;
  }
  return 0;
}