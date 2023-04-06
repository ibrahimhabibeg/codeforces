#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxIndex(int a[], int n)
{
  int res = 0;
  for (int i = 1; i < n; i++)
    if (a[i] > a[res])
      res = i;
  return res;
}

int minIndex(int a[], int n)
{
  int res = 0;
  for (int i = 1; i < n; i++)
    if (a[i] < a[res])
      res = i;
  return res;
}

int main()
{
  int TC, n, a;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int mx = maxIndex(a, n), mn = minIndex(a, n), ans[30 * n][2], res = 0;
    if (a[mn] == 1 && a[mx] != 1)
      cout << "-1\n";
    else
    {
      while (a[mx] != a[mn])
      {
        ans[res][0] = mx + 1, ans[res++][1] = mn + 1;
        a[mx] = (a[mx] + a[mn] - 1) / a[mn];
        mx = maxIndex(a, n), mn = minIndex(a, n);
      }
      cout << res << "\n";
      for (int i = 0; i < res; i++)
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
  }
}