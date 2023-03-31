#include <bits/stdc++.h>
using namespace std;

bool numbersMatch(string s, string t)
{
  int sCount[26], tCount[26];
  for (int i = 0; i < 26; i++)
    sCount[i] = tCount[i] - 0;
  for (int i = 0; i < s.length(); i++)
  {
    sCount[s[i] - 'a']++;
    tCount[t[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
    if (sCount[i] != tCount[i])
      return false;
  return true;
}

int main()
{
  int TC, n, k;
  string s, t;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> k >> s >> t;
    bool isYes = n <= 3 ? s == t : numbersMatch(s, t);
    if (n == 4)
      isYes = isYes && s[1] == t[1] && s[2] == t[2];
    if (n == 5)
      isYes = isYes && s[2] == t[2];
    if (isYes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}