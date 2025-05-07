#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(log(b))
ll binpow(ll a, ll b)
{
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}