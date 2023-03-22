#include <bits/stdc++.h>
using namespace std;
int main() {
  int TC;
  cin >> TC;
  while (TC--)
  {
    int n, cnt0 = 0, cnt1 = 0, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      if (x == 0)
        cnt0++;
      else if (x == 1)
        cnt1++;
    }
    if (cnt0 <= (n + 1) / 2)
      cout << 0 << "\n";
    else if (cnt1 == 0 || cnt1 + cnt0 < n)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
}