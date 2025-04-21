#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, a;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int mx = 0, p = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      mx = max(mx, a);
      s.insert(a);
    }
    if (mx == 0)
    {
      cout << "NO\n";
      continue;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
    {
      auto it = s.upper_bound(0);
      if (it==s.end() || p+*(it)>mx)
        it = prev(it);
      cout << *(it) << " ";
      p += *it;
      s.erase(s.find(*(it)));
    }
    cout << "\n";
  }
}