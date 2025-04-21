#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
  int TC;
  cin >> TC;
  while (TC--)
  {
    ll n;
    cin >> n;
    ll l = 0, r = (n + 3) / 4;
    while (l < r)
    {
      __int128 m = (l + r) / 2;
      if (m * m + 2 * m + 1 < n)
        l = m + 1;
      else
        r = m;
    }
    cout << l << "\n";
  }
}