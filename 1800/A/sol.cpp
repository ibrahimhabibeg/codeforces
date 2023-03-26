#include <bits/stdc++.h>
using namespace std;

char up[5] = {'M', 'E', 'O', 'W'};
char down[5] = {'m', 'e', 'o', 'w'};

int main()
{
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    char s[n + 1];
    cin >> s;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      if (i != 0 && j < 4 && (s[i] == up[j + 1] || s[i] == down[j + 1]))
        j++;
      else if (s[i] != up[j] && s[i] != down[j])
      {
        j = -1;
        break;
      }
    }
    if (j == 3)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}