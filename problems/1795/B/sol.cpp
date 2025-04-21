#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, k, l, r;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> k;
    bool isMin = false, isMax = false;
    for (int i = 0; i < n; i++)
    {
      cin >> l >> r;
      isMin = isMin || l == k, isMax = isMax || r == k;
    }
    if (isMin && isMax)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}