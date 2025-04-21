#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, t, l, r, x, n, q;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> q;
    int a[n + 1];
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      if (a[i] > 9) s.insert(i);
    }
    while (q--)
    {
      cin >> t;
      if (t == 1)
      {
        cin >> l >> r;
        auto it = s.lower_bound(l);
        while (it != s.end() && *it <= r)
        {
          int res = 0;
          while (a[*it]) res += a[*it] % 10, a[*it] /= 10;
          a[*it] = res;
          auto oldIt = it;
          it = next(it);
          if (res <= 9) s.erase(oldIt);
        }
      }
      else { cin >> x; cout << a[x] << "\n"; }
    }
  }
}