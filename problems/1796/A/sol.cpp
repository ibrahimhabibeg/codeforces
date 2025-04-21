#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s = "FBFFBFFBFBFFBFFBFBFFBFFB", t;
  int TC, k;
  cin >> TC;
  while (TC--)
  {
    cin >> k >> t;
    if (s.find(t) == string::npos)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}