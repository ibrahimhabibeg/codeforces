#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int ans = 0;
    string res = "";
    if (n % 2 == 0)
    {
      cout << "-1\n";
      continue;
    }
    while (n > 1)
    {
      ans++;
      if ((n - 1) % 4 != 0)
      {
        res = "2 " + res;
        n = (n - 1) / 2;
      }
      else
      {
        res = "1 " + res;
        n = (n + 1) / 2;
      }
    }
    cout << ans << "\n";
    cout << res << "\n";
  }
}