#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, mn, mx;
  cin >> TC;
  while (TC--)
  {
    cin >> mx >> mn;
    cout << 2 * (mx - mn) << "\n";
    for (int i = mn; i < mx; i++)
      cout << i << " ";
    for (int i = mx; i > mn; i--)
      cout << i << " ";
    cout << "\n";
  }
}