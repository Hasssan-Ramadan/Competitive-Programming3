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

class UnionFind
{
private:
  vi p, rank;

public:
  UnionFind(int N)
  {
    rank.assign(N + 1, 0);
    p.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
      p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j)
  {
    if (!isSameSet(i, j))
    {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else
      {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }
};

int main()
{
  setIO();
  int T, n, x, y, cont1, cont2;
  char c;
  string s;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++)
  {
    scanf("%d", &n);
    UnionFind u(n);
    cont1 = cont2 = 0;
    while (1)
    {
      if (!getline(cin, s) || s.empty())
        break;
      sscanf(s.c_str(), "%c %d %d", &c, &x, &y);
      if (c == 'c')
        u.unionSet(x, y);
      else
        u.isSameSet(x, y) ? cont1++ : cont2++;
    }
    if (tc != 1)
      printf("\n");
    printf("%d,%d\n", cont1, cont2);
  }
  return 0;
}
