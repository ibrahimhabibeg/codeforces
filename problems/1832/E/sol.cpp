#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 998244353;

int main(){
  int n, a1, m, k;
  ll x, y;
  scanf("%d %d %lld %lld %d %d", &n, &a1, &x, &y, &m, &k);
  ll a[n];
  vector<vector<ll>> dp(n, vector<ll>(k+1));
  a[0] = dp[0][0] = dp[0][1] = a1;
  for (int i = 1; i < n; i++) a[i] = (a[i-1]*x+y)%m;
  for (int i = 1; i < n; i++) dp[i][0] = (dp[i-1][0] + a[i])%MOD;
  for (int i = 2; i < k; i++) dp[0][k] = 0;
  for (int i = 1; i < n; i++) for (int j = 1; j<=k; j++) dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]+(j==1?a[i]:0))%MOD;
  ll res = 0;
  for (int i = 0; i < n; i++) res^=dp[i][k]*(i+1);
  printf("%lld\n", res);
}