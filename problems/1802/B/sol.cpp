#include <bits/stdc++.h>
using namespace std;
int main()
{
  int TC, n, val;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int noPigs = 0, noUsed = 0, noBought = 0;
    while (n--)
    {
      cin >> val;
      if (val == 1)
      {
        noPigs++;
        noUsed++;
        if (noUsed > noBought)
          noBought++;
      }
      else
        noUsed = noPigs == 0 ? 0 : 1 + noPigs / 2;
    }
    cout << noBought << "\n";
  }
}