#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC;
  ll a, b;
  cin >> TC;
  while (TC--)
  {
    cin >> a >> b;
    ll ans = a + b;
    for (int i = 1; i < 100000; i++)
      ans = min(ans, (a + i - 1) / i + (b + i - 1) / i + i - 1);
    cout << ans << "\n";
  }
}