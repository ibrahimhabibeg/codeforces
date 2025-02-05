#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll sum(ll a, ll b){
  return (a+b)%MOD;
}

ll mul(ll a, ll b) {
  return (a*b)%MOD;
}

ll modInverse(ll a) {
  ll M = MOD, m0 = M;
  ll y = 0, x = 1;
  if (M == 1) return 0;
  while (a > 1) {
    ll q = a / M;
    ll t = M;
    M = a % M, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}

void solve(){
  ll k, n;
  scanf("%lld%lld", &k, &n);
  if(k==1) {
    printf("%lld\n", n);
    return;
  }
  vector<ll> sz(k+1);
  for (int i = 2; i <= k; i++) {
    int d = 1, x = i;
    while (x>1){
      d++;
      while (x%d==0) x/=d, sz[i]++;
    }
  }
  vector<vector<ll>> c = vector(k+1, vector<ll>(1));
  for (int i = 2; i <= k; i++) c[i] = vector<ll>(sz[i] + 1), c[i][1] = 1;
  for (ll x = 2; x <= k; x++) for (ll s = 1; s <= sz[x]; s++) {
    ll m = 2;
    while (x*m<=k) {
      c[x*m][s+1] = sum(c[x*m][s+1], c[x][s]);
      m++;
    }    
  }
  ll S = 1;
  for (int i = 2; i <= k; i++) S = max(S, sz[i]);
  vector<ll> cmb(min(S+2, n+2));
  cmb[0] = 1;
  for(ll s = 1; s<=min(n+1, S+1); s++) cmb[s] = mul(mul(cmb[s-1], n+2-s), modInverse(s));
  printf("%lld ", n);
  for (ll x = 2; x <= k; x++) {
    ll r = 0;
    for (ll s = 1; s <= min(n, sz[x]); s++) r = sum(r, mul(c[x][s], cmb[s+1]));
    printf("%lld ", r);
  }
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}