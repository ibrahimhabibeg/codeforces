#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll TC, n, c, d;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> c >> d;
    ll a[n + 1] = {0};
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a, a + n + 1);
    ll curCost = 0, res = d + c * n;
    for (int i = 1; i <= n; i++)
    {
      if (a[i] - a[i - 1] > 1)
      {
        ll cost = curCost + c * (n - i + 1) + (i == 1 && a[i] != 1 ? d : 0);
        res = min(res, cost);
        curCost += d * (a[i] - a[i - 1] - 1);
      }
      else if (a[i] == a[i - 1])
        curCost += c;
    }
    res = min(res, curCost);
    cout << res << "\n";
  }
}