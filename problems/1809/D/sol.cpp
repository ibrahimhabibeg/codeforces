#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  const ll pow = 1e12;
  int TC;
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >> s;
    int cnt1 = 0, cnt0 = count(s.begin(), s.end(), '0');
    ll res = 1e18;
    if (s.length() == 1)
      res = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
      cnt1 += s[i] == '1', cnt0 -= s[i] == '0';
      ll del = cnt0 + cnt1 - (s[i] == '1') - (s[i + 1] == '0');
      res = min(res, (pow + 1) * del + (s[i] > s[i + 1]) * pow);
    }
    cout << res << "\n";
  }
}