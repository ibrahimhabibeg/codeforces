//////////////////////////////////////////////////////////////////////
///////////////           Wrong Answer             ///////////////////
//////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
int m, n, disI, disJ;
int dirArr[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int getNewChI(int i, int chI)
{
  if (i == n || i == 1)
    return chI == 1 ? -1 : 1;
  return chI;
}

int getNewChJ(int j, int chJ)
{
  if (j == m || j == 1)
    return chJ == 1 ? -1 : 1;
  return chJ;
}

int dirToPrime(int chI, int chJ)
{
  if (chI == 1 && chJ == 1)
    return 2;
  if (chI == -1 && chJ == 1)
    return 3;
  if (chI == 1 && chJ == -1)
    return 5;
  return 7;
}

bool moveIsPossible(int i, int j, int chI, int chJ)
{
  return i + chI >= 1 && i + chI <= n && j + chJ >= 1 && j + chJ <= m;
}

int DFS(int i, int j, int chI, int chJ, int *memo)
{
  int p = dirToPrime(chI, chJ);
  while (*(memo + (i - 1) * m + j - 1) % p != 0 && (i != disI || j != disJ) && moveIsPossible(i, j, chI, chJ))
  {
    *(memo + (i - 1) * m + j - 1) *= p;
    i += chI;
    j += chJ;
  }
  if (i == disI && j == disJ)
    return 0;
  if (*(memo + (i - 1) * m + j - 1) % p == 0)
    return -1;
  *(memo + (i - 1) * m + j - 1) *= p;
  int res = DFS(i, j, getNewChI(i, chI), getNewChJ(j, chJ), memo);
  if (res == -1)
    return -1;
  return 1 + res;
}

int main()
{
  int TC, i, j;
  string dir;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m >> i >> j >> disI >> disJ >> dir;
    int memo[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        memo[i][j] = 1;
    int chI = dir == "DR" || dir == "DL" ? 1 : -1, chJ = dir == "DR" || dir == "UR" ? 1 : -1;
    int res = DFS(i, j, chI, chJ, (int *)memo);
    cout << res << "\n";
  }
}
