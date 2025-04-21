#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 998244353;
const int MAX_N = 2025;
unordered_map<int, int> mp;
vector<int> p, c;
ll memo[2*MAX_N][MAX_N];
ll f[2*MAX_N];

bool isPrime(int n){
  if(n==1) return false;
  for (int i = 2; i <= sqrt(n); i++) if(n%i==0) return false;
  return true;
}

ll inv(ll x){
  int y = MOD - 2;
  ll z = 1;
  while (y){
    if(y%2==1) z = (z*x)%MOD;
    y/=2;
    x = (x*x)%MOD;
  }
  return z%MOD;
}

ll dp(int i, int q){
  if(i==-1 && q==0) return 1;
  if(i==-1 || q==-1 || q>i+1) return 0;
  if(memo[i][q]>=0) return memo[i][q];
  return memo[i][q] = (f[mp[p[i]]]*dp(i-1,q) + f[mp[p[i]]-1]*dp(i-1,q-1))%MOD;
}

int main(){
  memset(memo, -1, sizeof(memo));
  int n, x;
  scanf("%d", &n);
  int mx_cnt = 0;
  for (int i = 0; i < 2*n; i++){
    scanf("%d", &x);
    mx_cnt = max(mx_cnt, ++mp[x]);
    if(mp[x]==1 && isPrime(x)) p.push_back(x);
    else if(mp[x]==1) c.push_back(x);
  }
  f[0] = f[1] = 1;
  ll res = 1;
  for (int i = 2; i <= 2*n; i++) f[i] = (f[i-1]*inv(i))%MOD;
  for(int i = 1; i<=n; i++) res = (res*1LL*i)%MOD;
  for (int y: c) res = (res*f[mp[y]])%MOD;
  res = (res * dp(p.size()-1, n))%MOD;
  printf("%lld", res);
}