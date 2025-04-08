#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  ll n, k, x;
  scanf("%lld%lld%lld", &n, &k, &x);
  ll a[n], s = 0;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]), s += a[i];
  ll p = 0, w = 0;
  for (int i = n-1; i >= 0; i--) {
    p += a[i];
    if(p>=x) break;
    w += min(k, (x-1-p)/s+1);
  }
  printf("%lld\n", n*k - w);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}