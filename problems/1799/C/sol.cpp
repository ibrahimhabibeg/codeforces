#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int a[], int start)
{
  while (a[start] == 0 && start < 26)
    start++;
  if (start == 26)
    return "";
  if (a[start] > 1)
  {
    a[start] -= 2;
    return char(start + 'a') + solve(a, start) + char(start + 'a');
  }
  int next = start + 1;
  while (a[next] == 0 && next < 26)
    next++;
  int next2 = next + 1;
  while (a[next2] == 0 && next2 < 26)
    next2++;
  if (next < 26 && a[next] > 1 && next2 >= 26)
  {
    a[next] -= 2;
    return char(next + 'a') + solve(a, start) + char(next + 'a');
  }
  string res = "";
  char end = char(start + 'a');
  while (start++ < 25)
    for (int i = 0; i < a[start]; i++)
      res += char(start + 'a');
  return res + end;
}

int main()
{
  int TC;
  string s;
  cin >> TC;
  int a[26];
  while (TC--)
  {
    cin >> s;
    for (int i = 0; i < 26; i++)
      a[i] = 0;
    for (int i = 0; i < s.length(); i++)
      a[s[i] - 'a']++;
    cout << solve(a, 0) << "\n";
  }
}