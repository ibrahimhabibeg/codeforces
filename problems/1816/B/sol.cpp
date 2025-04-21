#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cout << (((i % 2) == 0) ? 2 * n - i : i + 1) << " ";
    cout << "\n";
    for (int i = 0; i < n - 1; i++)
      cout << (((i % 2) == 1) ? 2 * n - i - 2 : i + 1) << " ";
    cout << 2 * n - 1 << "\n";
  }
}