#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll GCF(ll a, ll b)
{
  while (b != 0)
  {
    ll c = a;
    a = b, b = c % b;
  }
  return a;
}

ll LCM(ll a, ll b)
{
  return a * b / GCF(a, b);
}

int main()
{
  ll TC, n, a, b, M, F;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> F >> M;
    F*=M;
    ll res = 1;
    for (ll i = 0; i < n - 1; i++)
    {
      cin >> a >> b;
      F = GCF(F, a*b), M = LCM(M, b);
      if(F%M!=0)
        res++, F = a * b, M = b;
    }
    cout << res << "\n";
  }
}