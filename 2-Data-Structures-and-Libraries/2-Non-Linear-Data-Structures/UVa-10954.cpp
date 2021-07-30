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
 int N, x;
 while (scanf("%d", &N) && N)
 {
  priority_queue<int, vector<int>, greater<int>> PQ;
  for (int i = 0; i < N; ++i)
  {
   scanf("%d", &x);
   PQ.push(x);
  }
  int cost = 0;
  while (PQ.size() != 1)
  {
   x = PQ.top();
   PQ.pop();
   x += PQ.top();
   PQ.pop();
   cost += x;
   PQ.push(x);
  }
  printf("%d\n", cost);
 }
 return 0;
}