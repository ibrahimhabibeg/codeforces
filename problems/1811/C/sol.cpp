#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, b1, b2;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> b1;
    cout << b1 << " ";
    for (int i = 0; i < n - 2; i++)
    {
      cin >> b2;
      cout << min(b1, b2) << " ";
      b1 = b2;
    }
    cout << b1 << "\n";
  }
}