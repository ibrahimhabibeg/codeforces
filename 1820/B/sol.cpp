#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC;
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >> s;
    ll largest = 0, length = 0, fLength = -1;
    for (int i = 0; i < s.size(); i++)
    {
      if (s.at(i) == '1')
        length++;
      else
      {
        if (fLength == -1)
          fLength = length;
        largest = max(largest, length), length = 0;
      }
    }
    largest = max(largest, max(fLength, 0 * 1LL) + length);
    if (largest == s.size())
      cout << s.size() * 1LL * s.size() << "\n";
    else
      cout << ((largest + 1) / 2) * ((largest + 2) / 2) << "\n";
  }
}