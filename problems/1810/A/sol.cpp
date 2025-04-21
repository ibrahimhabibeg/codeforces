#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC, n, a;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    bool isYes = false;
    for (int i = 1; i <= n; i++)
    {
      cin >> a;
      isYes = isYes || a <= i;
    }
    if (isYes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}