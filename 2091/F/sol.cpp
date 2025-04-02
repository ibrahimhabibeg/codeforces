#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

void solve(){
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  string s[n];
  for (int i = n-1; i >= 0; i--) cin >> s[i];
  vector<ll> dp(m);
  for (int i = 0; i < m; i++) if(s[0][i]=='X') dp[i] = 1;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    int l = 0, r = 0;
    vector<ll> ndp(m);
    for (int j = 0; j < m; j++) {
      while (r<m && d>=abs(r-j)) sum = (sum+dp[r])%MOD, r++;
      while (l<m && d< abs(l-j)) sum = (sum-dp[l])%MOD, l++;
      if(s[i][j]=='X') ndp[j] = sum;
    }
    dp = ndp, ndp = vector<ll>(m), sum = 0, l = 0, r = 0;
    if(i==n-1) break;
    for (int j = 0; j < m; j++) {
      while (r<m && d*1ll*d>=1+(r-j)*1ll*(r-j)) sum = (sum+dp[r])%MOD, r++;
      while (l<m && d*1ll*d< 1+(l-j)*1ll*(l-j)) sum = (sum-dp[l])%MOD, l++;
      if(s[i+1][j]=='X') ndp[j] = sum;
    }
    dp = ndp;
  }
  ll res = 0;
  for (auto v: dp) res = (res+v)%MOD;
  res = (res+MOD)%MOD;
  printf("%lld\n", res);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}