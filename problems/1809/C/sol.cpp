#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> k;
    int p = 0, sum = 0;
    while (sum + n - p < k)
    {
      sum += n - p;
      p++;
    }
    int r = k - sum;
    for (int i = 0; i < p; i++)
      cout << (n - p - 1) * (n - p) + 1 << " ";
    if (k == 0)
      cout << "-1 ";
    else
      cout << (r - 1) * r + 1 << " ";
    for (int i = 0; i < n - p - 1; i++)
      cout << -2 * (i + 1) << " ";
    cout << "\n";
  }
}