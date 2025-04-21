#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n;
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    int bst[26];
    for (int i = 0; i < 26; i++) bst[i] = i;
    sort(bst, bst + 26, [&](int i, int j) { return cnt[i] > cnt[j]; });
    int k = 0, bestScore = -1;
    for (int i = 1; i <= 26; i++)
    {
      if (n % i == 0)
      {
        int score = 0;
        for (int j = 0; j < i; j++) score += min(n / i, cnt[bst[j]]);
        if (score > bestScore)
        {
          bestScore = score;
          k = i;
        }
      }
    }
    vector<int> c(26);
    for (int i = 0; i < k; i++) c[bst[i]] = n/k;
    string res = "";
    for (int i = 0; i < n; i++)
    {
      if (c[s[i] - 'a'] > 0)
      {
        res += s[i];
        c[s[i] - 'a']--;
      }
      else res += "-";
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      if (res[i] == '-')
      {
        while (c[j] == 0) j++;
        res[i] = (char)('a' + j);
        c[j]--;
      }
    }
    cout << n - bestScore << "\n" << res << "\n";
  }
}