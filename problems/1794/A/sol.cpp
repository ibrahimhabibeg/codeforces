#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    string s1, s2, s;
    for (int i = 0; i < 2*(n-1); i++)
    {
      cin >> s;
      if (s.length() == n - 1 && s1 == "")
        s1 = s;
      else if (s.length() == n - 1)
        s2 = s;
    }
    if (s1 == string(s2.rbegin(), s2.rend()))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}