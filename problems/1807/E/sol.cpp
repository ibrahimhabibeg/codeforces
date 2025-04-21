#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC, n;
  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int l = 0, r = n - 1;
    while (l < r)
    {
      int m = (l + r) / 2, lSize = 0;
      std::printf("? %d", m - l + 1);
      for (int i = l; i <= m; i++)
      {
        std::printf(" %d", i + 1);
        lSize += a[i];
      }
      std::printf("\n");
      std::fflush(stdout);
      int res;
      scanf("%d", &res);
      if (res > lSize)
        r = m;
      else
        l = m + 1;
    }
    std::printf("! %d\n", l + 1);
    std::fflush(stdout);
  }
}