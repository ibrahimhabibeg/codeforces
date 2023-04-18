#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, m, p, v;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    int a[n + 1];
    vector<int> la(n + m + 1), r(n + m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
      cin >> p >> v;
      r[a[p]] += i - la[a[p]], la[v] = i, a[p] = v;
    }
    for (int i = 1; i <= n; i++) r[a[i]] += m + 1 - la[a[i]];
    ll res = 0;
    for (int i = 1; i <= n + m; i++) res += r[i] * 1LL * (m + 1 - r[i]) + (r[i] * 1LL * (r[i] - 1)) / 2;
    cout << res << "\n";
  }
}