#include <bits/stdc++.h>
using namespace std;

int largestDigit(int n)
{
  int res = 0;
  while (n > 0)
  {
    res = max(res, n % 10);
    n /= 10;
  }
  return res;
}

int smallestDigit(int n)
{
  int res = 9;
  while (n > 0)
  {
    res = min(res, n % 10);
    n /= 10;
  }
  return res;
}

int main()
{
  int TC, l, r;
  cin >> TC;
  while (TC--)
  {
    cin >> l >> r;
    int sm = smallestDigit(l), lg = largestDigit(l), diff = lg - sm, res = l;
    while (diff < 9 && l < r)
    {
      l++;
      sm = smallestDigit(l);
      lg = largestDigit(l);
      if (lg - sm > diff)
      {
        diff = lg - sm;
        res = l;
      }
    }
    cout << res << '\n';
  }
}