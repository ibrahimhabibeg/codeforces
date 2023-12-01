#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, q;
  ll k;
  scanf("%d%d", &n, &q);
  ll a[n], b[n];
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  ll p[62];
  p[0] = 1;
  for (int i =1; i < 62; i++) p[i]=p[i-1]*2;
  while (q--){
    ll res = 0;
    for (int i = 0; i < n; i++) b[i] = a[i];
    scanf("%lld", &k);
    for (ll z=61; z>=0; z--){
      ll d = 0;
      for (int i = 0; i < n; i++){
        if(d>k) break;
        d+=max(p[z]-b[i],0*1ll);
      }
      if(d<=k){
        res+=p[z];
        for (int i = 0; i < n; i++) if(b[i]<p[z]) b[i] = 0;
        k-=d;
      }
      for (int i = 0; i < n; i++) if(b[i]>=p[z]) b[i]=b[i]%p[z];
    }
    printf("%lld\n", res);
  }
    
  
}