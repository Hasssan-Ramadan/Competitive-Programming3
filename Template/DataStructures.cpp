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

#define LSOne(S) (S & (-S))

#define EPS 1e-9

class UnionFind
{
private:
  vi p, rank;

public:
  UnionFind(int N)
  {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
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

class SegmentTree
{
private:
  vector<ll> st, A;
  ll n;

  ll left(ll p) { return p << 1; }

  ll right(ll p) { return (p << 1) + 1; }

  void build(ll p, ll L, ll R)
  {
    if (L == R)
    {
      st[p] = A[L];
    }
    else
    {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      st[p] = min(st[left(p)], st[right(p)]);
    }
  }

  void update(ll p, ll L, ll R, ll pos, ll val)
  {
    if (L == R)
    {
      st[p] = val;
    }
    else
    {
      ll mid = L + (R - L) / 2;
      if (pos <= mid)
      {
        update(left(p), L, mid, pos, val);
      }
      else
      {
        update(right(p), mid + 1, R, pos, val);
      }

      st[p] = min(st[left(p)], st[right(p)]);
    }
  }

  ll query(ll p, ll L, ll R, ll i, ll j)
  {
    if (i > R || j < L)
    {
      return 1e9;
    }

    if (L >= i && R <= j)
    {
      return st[p];
    }

    return min(query(left(p), L, (L + R) / 2, i, j), query(right(p), (L + R) / 2 + 1, R, i, j));
  }

public:
  SegmentTree(const vector<ll> &_A)
  {
    A = _A;
    n = (ll)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  void update(ll pos, ll val) { update(1, 0, n - 1, pos, val); }

  ll query(ll i, ll j) { return query(1, 0, n - 1, i, j); }
};

class FenwickTree
{
private:
  vi ft;

public:
  FenwickTree() {}
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int rsq(int b)
  {
    int sum = 0;
    for (; b; b -= LSOne(b))
      sum += ft[b];
    return sum;
  }
  int rsq(int a, int b)
  {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
  }
  void adjust(int k, int v)
  {
    for (; k < (int)ft.size(); k += LSOne(k))
      ft[k] += v;
  }
};
