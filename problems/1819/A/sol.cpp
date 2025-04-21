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
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int b[n];
    copy(a, a + n, b);
    sort(b, b + n);
    bool isDup = false;
    int mex = 0, i = 0;
    while (i < n && b[i] <= mex)
    {
      if (b[i] == mex)
        mex++;
      else
        isDup = true;
      i++;
    }
    if (i < n && b[i] == mex + 1)
    {
      bool found[mex];
      for (int j = 0; j < mex ; j++)
        found[j] = false;
      int j = 0;
      while (a[j] != mex + 1)
      {
        if (a[j] < mex)
          found[a[j]] = true;
        j++;
      }
      j = n - 1;
      while (a[j] != mex + 1)
      {
        if (a[j] < mex)
          found[a[j]] = true;
        j--;
      }
      bool isYes = true;
      for (int i = 0; i < mex ; i++)
      {
        if (!found[i])
        {
          isYes = false;
          break;
        }
      }
      if (isYes)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
    else
    {
      if (i < n || isDup)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
}