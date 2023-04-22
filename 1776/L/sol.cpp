#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll TC, n, a, b, p = 0;
  string s;
  cin >> n >> s;
  for (char c : s) p += c == '+';
  ll v = (n - 2 * p);
  cin >> TC;
  while (TC--)
  {
    cin >> a >> b;
    bool isYes = a == b ? v == 0 : (b * v) % (a - b) == 0 && (b * v) / (a - b) >= p - n && (b * v) / (a - b) <= p;
    if (isYes) cout << "YES\n";
    else cout << "NO\n";
  }
}