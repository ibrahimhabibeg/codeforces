#include <bits/stdc++.h>
using namespace std;
int main()
{
  int TC;
  cin >> TC;
  while (TC--)
  {
    char numbers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, x, mostRepeated = 0;
    for (int i = 0; i < 4; i++)
    {
      cin >> x;
      numbers[x - '0']++;
      mostRepeated = max(mostRepeated, numbers[x - '0']);
    }
    if (mostRepeated == 4)
      cout << "-1\n";
    else if (mostRepeated == 3)
      cout << "6\n";
    else
      cout << "4\n";
  }
}