#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;

int main()
{
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    vector<pr> a(n);
    multiset<int> mSet;
    for (auto &[x, y] : a)
      cin >> x >> y, mSet.insert(y);
    sort(a.begin(), a.end(), greater<>());
    int res = 1e9, maxAbove = -1e9;
    for (int i = 0; i < n; i++)
    {
      mSet.erase(mSet.find(a[i].second));
      if (maxAbove >= a[i].first)
        res = min(res, maxAbove - a[i].first);
      else
      {
        res = min(res, a[i].first - maxAbove);
        auto it = mSet.upper_bound(a[i].first);
        if (it != mSet.end())
          res = min(res, *it - a[i].first);
        if (it != mSet.begin() && *prev(it) > maxAbove)
          res = min(res, a[i].first - *prev(it));
      }
      maxAbove = max(maxAbove, a[i].second);
    }
    cout << res << "\n";
  }
}