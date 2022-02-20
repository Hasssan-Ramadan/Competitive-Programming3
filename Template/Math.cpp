// checks if the given number is prime or not
bool isPrime(long long n)
{
  if (n <= 1)
    return false;
  for (long long i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

// sum of odd numbers at a given range [l,r] (inclusive)
long long sumRange(long long l, long long r)
{
  return (r * (r + 1)) / 2 - ((l - 1) * ((l - 1) + 1)) / 2;
}

// sum of even numbers at a given range [l,r] (inclusive)
long long sumEvenRange(long long l, long long r)
{
  return (r / 2) * (r / 2 + 1) - ((l - 1) / 2) * ((l - 1) / 2 + 1);
}

// sum of odd numbers at a given range [l,r] (inclusive)
long long sumOddRange(long long l, long long r)
{
  return sumRange(l, r) - sumEvenRange(l, r);
}

