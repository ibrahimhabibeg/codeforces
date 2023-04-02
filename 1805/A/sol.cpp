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
    int y = 0, a;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      y ^= a;
    }
    if (n % 2 == 0 && y == 0)
      cout << "0\n";
    else if (n % 2 == 0)
      cout << "-1\n";
    else
      cout << y << "\n";
  }
}