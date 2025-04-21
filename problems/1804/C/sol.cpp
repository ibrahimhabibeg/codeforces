#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC;
  ll p, n, x;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> x >> p;
    ll prev = 0;
    for (int i = 1; i <= min(2 * n, p); i++)
    {
      prev = (prev + i) % n;
      if (prev == (n - x) % n)
      {
        prev = -1;
        break;
      }
    }
    if (prev == -1)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}