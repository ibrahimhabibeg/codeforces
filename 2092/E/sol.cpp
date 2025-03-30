#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll fastExp(ll a, ll n)
{
  ll res = 1;
  while(n){
    if(n & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}

void solve()
{
  ll n, m, k, e = 0, se = 0, x, y, c;
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 0; i < k; i++)
  {
    scanf("%lld%lld%lld", &x, &y, &c);
    bool isEdge = false;
    if (x == 1 && y > 1 && y < m)
      isEdge = true;
    if (x == n && y > 1 && y < m)
      isEdge = true;
    if (y == 1 && x > 1 && x < n)
      isEdge = true;
    if (y == m && x > 1 && x < n)
      isEdge = true;
    e += isEdge;
    se += isEdge && c;
  }
  se %= 2;
  if (e == 2 * 1ll * (n + m) - 8 && se == 1)
    printf("0\n");
  else if (e == 2 * 1ll * (n + m) - 8)
    printf("%lld\n", fastExp(2, n * m - k));
  else
    printf("%lld\n", fastExp(2, n * m - k - 1));
}

int main()
{
  int TC;
  scanf("%d", &TC);
  while (TC--)
  {
    solve();
  }
}