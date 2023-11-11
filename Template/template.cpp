#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;

#define LSOneValue(S) (S & (-S))
#define OnesCount(S) (__builtin_popcountll(S))

// 1-indexed
#define LSB(S) (__builtin_ffsll(S))
#define MSB(S) (64LL - __builtin_clzll(S))

#define EPS 1e-9
#define PI 3.14159265358979323846

#define endl '\n'

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
  
}