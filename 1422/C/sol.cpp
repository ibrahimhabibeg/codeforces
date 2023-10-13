#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9+7;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  ll p[n+1], dp[n+1];
  p[0] = 1, dp[0] = 0;
  for (int i = 1; i <=n; i++) p[i] = (p[i-1]*10)%MOD;
  for (int i = 1; i <=n; i++) dp[i] = (dp[i-1]+(i*p[i-1])%MOD)%MOD;
  ll res = 0;
  for (ll i = 0; i < n; i++){
    ll l = (i*(i-1)/2 + i)%MOD, c = s[i]-'0', r = n-i-1;
    res = (res+c*((l*p[r])%MOD + dp[r]))%MOD;
  }
  printf("%lld\n", res);
}