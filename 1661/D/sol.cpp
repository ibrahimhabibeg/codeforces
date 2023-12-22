#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  ll a[n+1], s[n+2], b[n+2], c[n+2], res = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  b[n] = b[n+1] = s[n] = s[n+1] = c[n+1] = 0;
  for (int i = n; i >= 1; i--){
    s[i] = s[i+1]+c[i+1];
    if(i+k<=n) s[i]-=c[i+k];
    b[i] = b[i+1] - s[i+1] + (min(i+1,k)-1)*1ll*c[i+1];
    c[i] = max(0*1ll,(a[i]-b[i]+min(i,k)-1)/min(i,k));
    res+=c[i];
  }
  printf("%lld\n", res);
  
}