#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, sum, x;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    ll sum = a[0] == 1 ? 1 : -1;
    for (int i = 1; i < n; i++)
    {
      if (a[i] > sum)
      {
        sum = -1;
        break;
      }
      sum += a[i];
    }
    if (sum == -1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}