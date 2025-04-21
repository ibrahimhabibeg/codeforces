#include <bits/stdc++.h>
using namespace std;
int main()
{
  int TC, bag;
  cin >> TC;
  while (TC--)
  {
    int sumEven = 0, sumOdd = 0, n;
    cin >> n;
    while (n--)
    {
      cin >> bag;
      if (bag % 2 == 0)
        sumEven += bag;
      else
        sumOdd += bag;
    }
    if (sumEven > sumOdd)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
