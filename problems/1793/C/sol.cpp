#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int l = 1, mn = 1, r = n, mx = n, a[n + 1];
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    while (l < r)
    {
      if (a[l] == mn || a[l] == mx)
        mn += a[l] == mn, mx -= a[l] == mx, l += 1;
      else if (a[r] == mn || a[r] == mx)
        mn += a[r] == mn, mx -= a[r] == mx, r -= 1;
      else
        break;
    }
    if (l < r)
      cout << l << " " << r << "\n";
    else
      cout << "-1\n";
  }
}