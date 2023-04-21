#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int res = 0;
    ll s = 0;
    priority_queue<ll> pq_mx;
    for (int i = m; i >= 2; i--)
    {
      pq_mx.push(a[i]);
      s += a[i];
      if (s > 0)
      {
        ll v = pq_mx.top();
        s -= 2 * v;
        res++;
        pq_mx.pop();
      }
    }
    s = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq_mn;
    for (int i = m + 1; i <= n; i++)
    {
      pq_mn.push(a[i]);
      s += a[i];
      if (s < 0)
      {
        ll v = pq_mn.top();
        s -= 2 * v;
        res++;
        pq_mn.pop();
      }
    }
    cout << res << "\n";
  }
}