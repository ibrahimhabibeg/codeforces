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
    int res = 0;
    for (int i = 1; i < n; i++)
      if (s[i] <= s[res])
        res = i;
    cout << s[res] + s.substr(0, res) + s.substr(res + 1, n - res) << "\n";
  }
}