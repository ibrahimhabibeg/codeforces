#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC;
  ll a, b, n, m;
  cin >> TC;
  while (TC--)
  {
    cin >> a >> b >> n >> m;
    cout << min(n * b, a * m * (n / (m + 1)) + (n % (m + 1)) * min(a, b)) << "\n";
  }
}