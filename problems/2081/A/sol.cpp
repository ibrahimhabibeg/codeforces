#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;
const int N = 1e5+5;
ll p[N];

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
ll modMul(ll a, ll b) {
  return (a * b) % MOD;
}
ll modAdd(ll a, ll b) {
  return (a + b) % MOD;
}
ll modSub(ll a, ll b) {
  return (a - b + MOD) % MOD;
}
ll modDiv(ll a, ll b) {
  return (a * modInverse(b, MOD)) % MOD;
}

void solve(){
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  s = '0' + s;
  ll dp[n+1][2], f[n+1], k = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = k;
    if(s[i]=='0') k = i;
  }
  dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = modAdd(p[i], modMul(2, dp[i-1][s[i-1]-'0']));
    dp[i][1] = modAdd(
      modMul(p[i-1], i-f[i]+1),
      modAdd(dp[i-1][s[i-1]-'0'], 
        modMul(p[i-1-f[i]], dp[f[i]][1])
      )
    );
  }
  printf("%lld\n", modDiv(dp[n][s[n]-'0'], p[n]));
}

int main(){
  int TC;
  scanf("%d", &TC);
  p[0] = 1;
  for (int i = 1; i <= N; i++) p[i] = modMul(p[i-1], 2);
  while(TC--){
    solve();
  }
}