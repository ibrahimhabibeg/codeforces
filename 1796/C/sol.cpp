#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;

int main()
{
  int TC;
  ll l, r;
  cin >> TC;
  while (TC--)
  {
    cin >> l >> r;
    ll s = 0, pow = 1;
    while (l * pow * 2 <= r)
    {
      s++;
      pow *= 2;
    }
    ll m2 = (r / pow) % mod;
    ll m3 = pow == 1 ? l - 1 : max(r / ((pow / 2) * 3), l - 1) % mod;
    cout << s + 1 << " " << (m2 - l + 1 + s * (m3 - l + 1)) % mod << "\n";
  }
}