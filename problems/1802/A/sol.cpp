#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC;
  cin >> TC;
  while (TC--)
  {
    int n, l = 0, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      l += x > 0 ? 1 : 0;
    }
    for (int i = 1; i <= l; i++)
      cout << i << " ";
    for (int i = l - 1; i >= 2 * l - n; i--)
      cout << i << " ";
    cout << "\n";
    for (int i = 0; i < n - l; i++)
      cout << "1 0 ";
    for (int i = 1; i <= 2 * l - n; i++)
      cout << i << " ";
    cout << "\n";
  }
}