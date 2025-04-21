#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, s, a;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> s;
    ll mn[n], mx[n], f[n][2];
    cin >> mn[0];
    mx[0] = mn[0];
    for (int i = 1; i < n-1; i++)
    {
      cin >> a;
      if (a <= s)
        mn[i] = 0, mx[i] = a;
      else
        mn[i] = min(s, a - s), mx[i] = max(s, a - s);
    }
    cin >> mn[n-1];
    mx[n-1] = mn[n-1];
    f[0][0] = f[0][1] = 0;
    for (int j = 1; j < n; j++)
    {
      f[j][0] = min(f[j - 1][0] + mx[j - 1] * mn[j], f[j - 1][1] + mn[j - 1] * mn[j]);
      f[j][1] = min(f[j - 1][0] + mx[j - 1] * mx[j], f[j - 1][1] + mn[j - 1] * mx[j]);
    }
    cout << f[n-1][0] << "\n";
  }
}