#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC, n;
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> s;
    int res = n - 1;
    for (int i = 0; i <= n - 3; i++)
      res -= s.at(i) == s.at(i + 2);
    cout << res << "\n";
  }
}