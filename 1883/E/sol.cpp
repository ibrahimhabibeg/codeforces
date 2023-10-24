#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  ll p[32];
  p[0]=1;
  for (int i = 1; i < 32; i++) p[i]=p[i-1]<<1;
  while (TC--){
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll res = 0, c = 0;
    for (int i = 1; i < n; i++){
      if(a[i-1]>=a[i]) c+=lower_bound(p,p+32,(a[i-1]+a[i]-1)/a[i])-p;
      else c=max(0*1LL,c-(upper_bound(p,p+32,a[i]/a[i-1])-p-1));
      res+=c;
    }
    printf("%lld\n", res);
  }   
}