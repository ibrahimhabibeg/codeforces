#include <bits/stdc++.h>
using namespace std;

int twoCharOverlap(string s1, string s2)
{
  for (int i = 0; i < s1.length() - 1; i++)
    for (int j = 0; j < s2.length() - 1; j++)
      if (s1.at(i) == s2.at(j) && s1.at(i + 1) == s2.at(j + 1))
        return i;
  return -1;
}

int main()
{
  int TC;
  cin >> TC;
  string s1, s2;
  while (TC--)
  {
    cin >> s1 >> s2;
    if (s1.at(0) == s2.at(0))
      cout << "YES\n"
           << s1.at(0) << "*\n";
    else if (s1.at(s1.length() - 1) == s2.at(s2.length() - 1))
      cout << "YES\n*"
           << s1.at(s1.length() - 1) << "\n";
    else
    {
      int i = twoCharOverlap(s1, s2);
      if (i != -1)
        cout << "YES\n*"
             << s1.at(i) << s1.at(i + 1) << "*\n";
      else
        cout << "NO\n";
    }
  }
}