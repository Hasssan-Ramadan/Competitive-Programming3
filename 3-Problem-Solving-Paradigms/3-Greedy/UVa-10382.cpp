#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define mp make_pair
#define LSOne(S) (S & (-S))
#define EPS 1e-9

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
 vi st, A;
 int n;
 int left(int p) { return p << 1; }
 int right(int p) { return (p << 1) + 1; }
 void build(int p, int L, int R)
 {
  if (L == R)
   st[p] = L;
  else
  {
   build(left(p), L, (L + R) / 2);
   build(right(p), (L + R) / 2 + 1, R);
   int p1 = st[left(p)], p2 = st[right(p)];
   st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }
 }
 int rmq(int p, int L, int R, int i, int j)
 {
  if (i > R || j < L)
   return -1;
  if (L >= i && R <= j)
   return st[p];
  int p1 = rmq(left(p), L, (L + R) / 2, i, j);
  int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
  if (p1 == -1)
   return p2;
  if (p2 == -1)
   return p1;
  return (A[p1] <= A[p2]) ? p1 : p2;
 }

public:
 SegmentTree(const vi &_A)
 {
  A = _A;
  n = (int)A.size();
  st.assign(4 * n, 0);
  build(1, 0, n - 1);
 }
 int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
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

const int maxn = 10000 + 10;
struct node
{
 double l, r;
 node() {}
 node(double ll, double rr) : l(ll), r(rr) {}
 bool operator<(const node &p) const
 {
  return l < p.l;
 }
};
node a[maxn];


int main()
{
 int n;
 double l, w;
 while (~scanf("%d %lf %lf", &n, &l, &w))
 {
  int indx = 0;
  double p, r;
  for (int i = 0; i < n; ++i)
  {
   scanf("%lf %lf", &p, &r);
   double x = sqrt(r * r - (w / 2.0) * (w / 2.0));
   if (2 * r > w)
    a[indx++] = node(p - x, p + x);
  }
  sort(a, a + indx);
  double s = 0, e = 0;
  int cnt = 1;
  if (a[0].l > s)
  {
   printf("-1\n");
   continue;
  }
  for (int i = 0; i < indx; ++i)
  {
   if (a[i].l <= s)
    e = max(e, a[i].r);
   else
   {
    ++cnt;
    s = e;
    if (a[i].l <= s)
     e = max(e, a[i].r);
    else
     break;
   }
   if (e >= l)
    break;
  }
  if (e < l)
   printf("-1\n");
  else
   printf("%d\n", cnt);
 }
 return 0;
}