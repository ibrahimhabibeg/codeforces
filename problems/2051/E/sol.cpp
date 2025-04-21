#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  ll n, k, x, res = 0;
  scanf("%lld%lld", &n, &k);
  pair<ll, int> a[2*n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x);
    a[i] = make_pair(x, 1);
  }
  for (int i = n; i < 2*n; i++) {
    scanf("%lld", &x);
    a[i] = make_pair(x, 2);
  }
  sort(a, a+2*n);
  ll noBuyers = n, negative = 0;
  int i = 0;
  while (i < 2*n){
    if(negative <= k) res = max(res, a[i].first*noBuyers);
    x = a[i].first;
    while (i < 2*n && a[i].first == x){
      if(a[i].second==1) negative++;
      else {
        noBuyers--;
        negative--;
      }
      i++;
    }
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