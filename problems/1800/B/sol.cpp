#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> k;
    char s[n + 1];
    cin >> s;
    int lower[26], upper[26];
    for (int i = 0; i < 26; i++)
      lower[i] = upper[i] = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] < 91)
        upper[s[i] - 'A']++;
      else
        lower[s[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
      int b = max(upper[i], lower[i]), l = min(upper[i], lower[i]);
      res += l + min((b - l) / 2, k);
      k -= min((b - l) / 2, k);
    }
    cout << res << "\n";
  }
}