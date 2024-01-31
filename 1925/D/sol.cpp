#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

ll gcdExtended(ll a, ll b, ll *x, ll *y){
  if (a == 0){
      *x = 0, *y = 1;
      return b;
  }
  ll x1, y1; 
  ll gcd = gcdExtended(b%a, a, &x1, &y1);
  *x = y1 - (b/a) * x1;
  *y = x1;
  return gcd;
}

ll modInverse(ll b){
  ll x, y; 
  gcdExtended(b, MOD, &x, &y);
  return (x%MOD + MOD) % MOD;
}

int main(){
  int TC;
  ll x, y, f;
  ll n, m, k;
  cin >> TC;
  while (TC--){
    scanf("%lld%lld%lld", &n, &m, &k);
    ll s = 0, pr = (n*(n-1)/2)%MOD;
    for (int i = 0; i < m; i++) scanf("%lld%lld%lld", &x, &y, &f), s = (s+f)%MOD;
    if(n==2){
      ll res = (((k*(k-1)/2)%MOD) + ((k*s)%MOD))%MOD;
      if(m==0) printf("0\n");
      else printf("%lld\n", res);
      continue;
    }
    ll invPr = modInverse(pr), invPrM1 = modInverse(pr-1);
    ll res = (((k*s)%MOD)*invPr)%MOD, v = 1;
    for (int i = 0; i < k; i++) v = ((v*(pr-1)%MOD)*invPr)%MOD;
    for (ll r = 1; r <= k; r++){
      v = (((((v*invPrM1)%MOD)*(k-(r-1)))%MOD)*modInverse(r))%MOD;
      ll ad = (((((r*(r-1)/2)%MOD) * m)%MOD)*v)%MOD;
      res = (res + ad)%MOD;
    }
    printf("%lld\n", res);
  }   
}