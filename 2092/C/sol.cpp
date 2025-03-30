#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  ll a[n];
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  ll odd = 0, even = 0, mx = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if(a[i]%2) odd++;
    else even++;
    mx = max(mx, a[i]);
    sum += a[i];
  }
  if(odd==0 || even==0) printf("%lld\n", mx);
  else printf("%lld\n", sum - odd + 1*1ll);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}