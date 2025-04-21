#include <bits/stdc++.h>
using namespace std;
int main()
{
  int TC, n, k, d, w, t;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> k >> d >> w;
    int res = 1, initT, bucketSize = 1;
    cin >> initT;
    for (int i = 0; i < n - 1; i++)
    {
      cin >> t;
      if (bucketSize >= k || initT + w + d < t)
      {
        res++;
        initT = t;
        bucketSize = 1;
      }
      else
        bucketSize++;
    }
    cout << res << "\n";
  }
}