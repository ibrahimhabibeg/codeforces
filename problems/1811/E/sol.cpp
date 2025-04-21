#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC;
  ll x;
  cin >> TC;
  while (TC--)
  {
    cin >> x;
    vector<int> v;
    while (x > 0)
    {
      v.push_back(x % 9);
      x /= 9;
    }
    for (int i = v.size() - 1; i >= 0; i--)
      cout << (v[i] >= 4 ? v[i] + 1 : v[i]);
    cout << "\n";
  }
}