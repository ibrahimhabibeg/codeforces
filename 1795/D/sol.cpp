#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

int mul(int x, int y)
{
  return x * 1LL * y % mod;
}

int binpow(int x, int y)
{
  int z = 1;
  while (y)
  {
    if (y % 2 == 1)
      z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}

int inv(int x)
{
  return binpow(x, mod - 2);
}

int divide(int x, int y)
{
  return mul(x, inv(y));
}

int main()
{
  int n, a[3];
  cin >> n;
  int res = 1;
  for (int i = 1; i <= n / 6; i++)
    res = mul(res, divide(n / 3 - i + 1, i));
  for (int i = 0; i < n / 3; i++)
  {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] == a[1] && a[1] == a[2])
      res = mul(res, 3);
    else if (a[0] == a[1])
      res = mul(res, 2);
  }
  cout << res << "\n";
}