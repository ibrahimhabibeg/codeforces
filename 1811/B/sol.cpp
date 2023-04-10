#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, x1, y1, x2, y2;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> x1 >> y1 >> x2 >> y2;
    cout << abs(min(min(x1 - 1, n - x1), min(y1 - 1, n - y1)) - min(min(x2 - 1, n - x2), min(y2 - 1, n - y2))) << "\n";
  }
}