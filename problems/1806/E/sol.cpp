#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
ll w[N], p[N];
unordered_map<int, ll> memo[N];

ll f(int u, int v) {

  if (u == 0)
    return 0;
  if (u > v)
    swap(u, v);
  if (memo[u][v])
    return memo[u][v];
  return memo[u][v] = w[u] * w[v] + f(p[u], p[v]);
}

int main() {
  int n, q, u, v, T;
  ll res;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 2; i <= n; i++)
    cin >> p[i];
  p[1] = 0;
  while (q--)
  {
    cin >> u >> v;
    T = 1e3, res = 0;
    while (T-- && u)
    {
      res += w[u] * w[v];
      u = p[u];
      v = p[v];
    }
    cout << res + f(u, v) << "\n";
  }
  return 0;
}