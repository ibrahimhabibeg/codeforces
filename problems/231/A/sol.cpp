#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, val, res = 0;
  cin >> n;
  while (n--)
  {
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
      cin >> val;
      count += val;
    }
    if (count > 1)
      res++;
  }
  cout << res;
}