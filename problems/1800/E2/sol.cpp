#include <bits/stdc++.h>
using namespace std;

bool numbersMatch(string s, string t, int n, int k)
{
  int sCount[26], tCount[26];
  for (int i = 0; i < 26; i++)
    sCount[i] = tCount[i] - 0;
  for (int i = 0; i < n - k; i++)
  {
    sCount[s[i] - 'a']++;
    tCount[t[i] - 'a']++;
  }
  for (int i = max(k, n - k); i < n; i++)
  {
    sCount[s[i] - 'a']++;
    tCount[t[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
    if (sCount[i] != tCount[i])
      return false;
  return true;
}

bool stringPortionEquals(string s, string t, int n, int k)
{
  for (int i = max(0, n - k); i < min(k, n); i++)
    if (s[i] != t[i])
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
    if (numbersMatch(s, t, n, k) && stringPortionEquals(s, t, n, k))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}