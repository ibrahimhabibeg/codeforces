#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n; 
  ll a;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      s += i % 2 == 1 ? a : -a;
    }
    if (n % 2 == 1 || s >= 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}