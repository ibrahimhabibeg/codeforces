#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, x, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int a[n], d[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> d[i];
    ll p[n + 1] = {0};
    for (int i = 0; i < n; i++) p[i + 1] = d[i] + p[i];
    vector<ll> last(n + 1), cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
      int j = upper_bound(p, p + n + 1, a[i] + p[i]) - p - 1;
      last[j] += a[i] - p[j] + p[i];
      cnt[i]++, cnt[j]--;
    }
    for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) cout << last[i] + d[i] * 1LL * cnt[i] << " ";
    cout << "\n";
  }
}