#include <bits/stdc++.h>
using namespace std;
int main()
{
  int TC, x, y;
  cin >> TC;
  while (TC--)
  {
    cin >> x >> y;
    x = abs(x), y = abs(y);
    cout << 2 * min(x, y) + 2 * (max(x, y) - min(x, y)) + (x == y ? 0 : -1) << "\n";
  }
}