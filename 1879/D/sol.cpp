#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;

int main(){
  int n;
  scanf("%d", &n);
  ll a[n], res = 0;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int z = 0; z <= 30; z++){
    ll b[n], co = 1, lo = -1, ce = 0, le = 0, s=0;
    b[0] = a[0]%2, a[0]/=2;
    for (int i = 1; i < n; i++) b[i] = b[i-1] + a[i]%2, a[i]/=2;
    for (int i = 0; i < n; i++) {
      if(b[i]%2){
        s = (s+((co*i-lo)%MOD))%MOD;
        ce++, le+=i;
      }else{
        s = (s+((ce*i-le)%MOD))%MOD;
        co++, lo+=i;
      }
    }
    res = (res + (((1<<z)*s)%MOD))%MOD;
  }
  printf("%lld\n", res); 
}