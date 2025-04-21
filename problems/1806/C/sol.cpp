#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC;
  ll n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    ll a[2 * n], res = 0, sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
      cin >> a[i];
      res += abs(a[i]);
      sum += abs(a[i] + 1);
    }
    if (n == 1)
      res = min(res, abs(a[0] - a[1]));
    if (n == 2)
      res = min(res, abs(a[0] - 2) + abs(a[1] - 2) + abs(a[2] - 2) + abs(a[3] - 2));
    if (n % 2 == 0)
      for (int i = 0; i < 2 * n; i++)
        res = min(res, sum + abs(a[i] - n) - abs(a[i] + 1));
    cout << res << "\n";
  }
}