#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, t;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> t;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    int res = -1, joy = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] + i <= t && b[i] > joy)
      {
        res = i + 1;
        joy = b[i];
      }
    }
    cout << res << "\n";
  }
}