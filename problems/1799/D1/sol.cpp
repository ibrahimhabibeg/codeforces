#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e13;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &k);
    vector<ll> dp(k,INF);
    int t[n]; 
    ll h[k], c[k];
    for (int i = 0; i < n; i++) scanf("%d", &t[i]), t[i]--;
    for (int i = 0; i < k; i++) scanf("%lld", &c[i]);
    for (int i = 0; i < k; i++) scanf("%lld", &h[i]);
    dp[t[0]] = c[t[0]];
    int y = t[0];
    for (int i = 1; i < n; i++)
    {
      int x = t[i];
      vector<ll> ndp(k,INF);
      ndp[x] = min(ndp[x], dp[x]+h[x]);
      ndp[y] = min(ndp[y], dp[x]+h[x]);
      for (int j = 0; j < k; j++)
      {
        ndp[x] = min(ndp[x], dp[j]+(x==y?h[x]:c[x]));
        ndp[j] = min(ndp[j], dp[j]+(x==y?h[x]:c[x]));
      }
      y = x;
      dp = ndp;
    }
    ll res = INF;
    for (int i = 0; i < k; i++) res = min(res, dp[i]);
    printf("%lld\n", res);
  }   
}