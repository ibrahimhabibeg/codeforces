#include <bits/stdc++.h>
using namespace std;
int main() {
  int TC, x, y, xf, yf;
  cin >> TC;
  while (TC--)
  {
    cin >> x >> y >> xf >> yf;
    if (yf < y || x + yf - y < xf)
      cout << -1 << "\n";
    else
      cout << 2 * yf - 2 * y + x + -xf << "\n";
  }
}