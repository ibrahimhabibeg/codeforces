#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll N = 5e5 + 5;
ll memo[26][N], n, a[26];

ll dp(int i, ll v) {
  if(i==-1) {
    if(v == n/2) return 1;
    else return 0;
  }
  if(memo[i][v]!=-1) return memo[i][v];
  if(a[i]) memo[i][v] = (dp(i-1, v) + dp(i-1, v+a[i])) % MOD;
  else memo[i][v] = dp(i-1, v);
  return memo[i][v];
}

ll modInverse(ll a, ll m) {
  ll m0 = m, t, q;
  ll x0 = 0, x1 = 1;
  if (m == 1) return 0;
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0) x1 += m0;
  return x1;
}

void solve(){
  n = 0;
  for (int i = 0; i < 26; i++) scanf("%d", &a[i]), n+=a[i];
  for (int i = 0; i < 26; i++) for (int j = 0; j <= n; j++) memo[i][j] = -1;
  ll r = dp(25, 0);
  for (int i = 1; i <= n/2; i++) r = (r*i) % MOD;
  for (int i = 1; i <= (n+1)/2; i++) r = (r*i) % MOD;
  ll f = 1;
  for (int i = 0; i < 26; i++) for (int j = 1; j<=a[i]; j++) f = (f*j)%MOD;
  r = (r*modInverse(f, MOD))%MOD;
  printf("%lld\n", r);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}