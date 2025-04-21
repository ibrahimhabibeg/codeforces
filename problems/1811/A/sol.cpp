#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n;
  char d;
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> d >> s;
    int i = 0;
    while (i < n && s[i] >= d)
      i++;
    cout << s.substr(0, i) + d + s.substr(i, n - i) << "\n";
  }
}