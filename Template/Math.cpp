#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

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

// checks if the given number is prime or not
bool isPrime(ll n)
{
  if (n <= 1)
    return false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

// sum of odd numbers at a given range [l,r] (inclusive)
ll sumRange(ll l, ll r)
{
  return (r * (r + 1)) / 2 - ((l - 1) * ((l - 1) + 1)) / 2;
}

// sum of even numbers at a given range [l,r] (inclusive)
ll sumEvenRange(ll l, ll r)
{
  return (r / 2) * (r / 2 + 1) - ((l - 1) / 2) * ((l - 1) / 2 + 1);
}

// sum of odd numbers at a given range [l,r] (inclusive)
ll sumOddRange(ll l, ll r)
{
  return sumRange(l, r) - sumEvenRange(l, r);
}

// sum numbers in range [l, r] (inclusive) that is divisible by k
ll sumRangeDivByX(ll l, ll r, ll x)
{
  return (((r / x) * ((r / x) + 1)) / 2 - (((l - 1) / x) * (((l - 1) / x) + 1)) / 2) * x;
}

// multiply 2 matrices & return the multiplication martix
vector<vi> mul2Matrices(vector<vi> &a, vector<vi> &b)
{
  int ra = a.size(), ca = a[0].size(), rb = b.size(), cb = b[0].size();
  vector<vi> ab(ra, vi(cb));
  for (int i = 0; i < ra; i++)
    for (int j = 0; j < cb; j++)
      for (int k = 0; k < ca; k++)
        ab[i][j] += a[i][k] * b[k][j];
  return ab;
}

// get sum of all n factors (divisors)
ll sumAllDivisors(ll n)
{
  ll sum = 0;
  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      sum += i;
      if (i != sqrt(n))
        sum += n / i;
    }
  }
  return sum;
}

// get divisors of n
vector<ll> getDivisors(ll n)
{
  vector<ll> divisors;
  for (ll i = 2; i <= sqrt(n); ++i)
  {
    if (n % i == 0)
    {
      divisors.push_back(i);
      if (i != sqrt(n))
        divisors.push_back(n / i);
    }
  }
  return divisors;
}

// get prime factors of given number n - returns a vector of pairs <prime factor, power>
vector<pair<ll, ll>> getPrimeFactors(ll n)
{
  vector<pair<ll, ll>> primeFactors;
  for (ll i = 2; i * i <= n; i++)
  {
    pair<ll, ll> curr_p = mp(i, 0);
    while (n % i == 0)
    {
      curr_p.s++;
      n /= i;
    }
    if (curr_p.s)
      primeFactors.pb(curr_p);
  }
  if (n > 1)
    primeFactors.pb(mp(n, 1));
  return primeFactors;
}

// calculate Combination (nCr) - n choose r
// (order doesn't matter + without repetition)
ull nCr(int n, int r)
{
  if (r > n)
    return 0;
  r = max(r, n - r);
  ull ans = 1, div = 1, i = r + 1;
  while (i <= n)
  {
    ans *= i;
    i++;
    ans /= div;
    div++;
  }
  return ans;
}

// calculate Permutation (nPr)
// (order matters + without repetition)
ull nPr(int n, int r)
{
  if (r > n)
    return 0;
  ull p = 1, i = n - r + 1;
  while (i <= n)
    p *= i++;
  return p;
}

// get greatest common divisor of 2 numbers
ll gcd(ll a, ll b)
{
  if (a < b)
    swap(a, b);
  while (a != 0 && b != 0)
  {
    ll r = a % b;
    a = b;
    b = r;
  }
  return a;
}

// get least common multiple of 2 numbers
ll lcm(ll a, ll b)
{
  return a / gcd(a, b) * b;
}