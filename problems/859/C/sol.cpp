
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int TC, n, map[26];
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    for (int i = 0; i < 26; i++)
      map[i] = -1;
    string s;
    cin >> s;
    map[s.at(0) - 'a'] = 0;
    bool isCorrect = true;
    for (int i = 1; i < n; i++)
    {
      if (map[s.at(i) - 'a'] == map[s.at(i - 1) - 'a'])
      {
        cout << "NO\n";
        isCorrect = false;
        break;
      }
      else if (map[s.at(i) - 'a'] == -1)
      {
        map[s.at(i) - 'a'] = map[s.at(i - 1) - 'a'] == 0 ? 1 : 0;
      }
    }
    if (isCorrect)
      cout << "YES\n";
  }
}
