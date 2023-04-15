#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC;
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >> s;
    int res = 0, length = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s.at(i) == '_')
        length++;
      else
        res += max(0, length - 1), length = 0;
    }
    if(s.size()==1 && s.at(0)=='^')
      cout << "1\n";
    else
      cout << res + max(0, length - 1) + (s.at(0) == '_') + (s.at(s.size() - 1) == '_') << "\n";
  }
}