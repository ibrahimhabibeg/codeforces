#include <bits/stdc++.h>
using namespace std;

int dirToKey(int chI, int chJ)
{
  if (chI == 1 && chJ == 1)
    return 0;
  if (chI == -1 && chJ == 1)
    return 1;
  if (chI == 1 && chJ == -1)
    return 2;
  else
    return 3;
}

int main()
{
  int TC, i, j, n, m, disI, disJ;
  string dir;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m >> i >> j >> disI >> disJ >> dir;
    int memo[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        memo[i][j] = 0;
    int bounces = 0, chI = dir[0] == 'D' ? 1 : -1, chJ = dir[1] == 'R' ? 1 : -1;
    int d = 1 << dirToKey(chI, chJ);
    bool solFound = false;
    while ((memo[i][j] & d) == 0)
    {
      memo[i][j] |= d;
      if (i == disI && j == disJ)
      {
        solFound = true;
        break;
      }
      int newChI = chI, newChJ = chJ;
      if (i == 1)
        newChI = 1;
      else if (i == n)
        newChI = -1;
      if (j == 1)
        newChJ = 1;
      else if (j == m)
        newChJ = -1;
      bounces += chI != newChI || chJ != newChJ, chI = newChI, chJ = newChJ;
      i += chI, j += chJ, d = 1 << dirToKey(chI, chJ);
    }
    if (solFound)
      cout << bounces << "\n";
    else
      cout << "-1\n";
  }
}