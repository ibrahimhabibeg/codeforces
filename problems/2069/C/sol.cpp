#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

void solve(){
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  ll s = 0, c = 0, res = 0;
  for (int i = n-1; i>=0; i--) {
    if(a[i]==3) c = (c+1)%MOD, s = (s+1)%MOD;
    else if(a[i]==2) s = (s*2)%MOD;
    else res = (((res + s - c) % MOD) + MOD)%MOD;
  }
  printf("%lld\n", res);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}