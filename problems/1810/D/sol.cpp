#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll neededN(ll a, ll b, ll h)
{
  return max(1LL, (h - b - 1) / (a - b));
}

int main()
{
  ll TC, q, t, a, b, n;
  cin >> TC;
  while (TC--)
  {
    cin >> q;
    ll maxH = 1e18, minH = 1;
    while (q--)
    {
      cin >> t >> a >> b;
      if (t == 2)
      {
        ll resL = max(1LL, (minH - b - 1) / (a - b) + 1), resR = max(1LL, (maxH - b - 1) / (a - b) + 1);
        if (resL == resR)
          cout << resL << " ";
        else
          cout << "-1 ";
      }
      else
      {
        cin >> n;
        ll newMaxH = a + (a - b) * (n - 1), newMinH = n == 1 ? 1 : a + 1 + (a - b) * (n - 2);
        if (n == 1)
          newMinH = 1, newMaxH = a;
        if (newMaxH < minH || newMinH > maxH)
          cout << "0 ";
        else
          maxH = min(maxH, newMaxH), minH = max(minH, newMinH), cout << "1 ";
      }
    }
    cout << "\n";
  }
}