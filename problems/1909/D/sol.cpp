#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  while (b){
    ll c = a;
    a = b, b = c%b;
  }
  return a;
}

int main(){
  int TC, n;
  ll k;
  cin >> TC;
  while (TC--){
    scanf("%d%lld", &n, &k);
    ll a[n], s = 0, mn=1e12+5, mx=0;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), s+=a[i], mn = min(mn,a[i]), mx = max(mx, a[i]);
    if(mn==k && mx==k) printf("0\n");
    else if(mn>k || mx<k){
      ll d = 0;
      for (int i = 0; i < n; i++) d = gcd(d, abs(a[i]-k));
      if(mn>k) printf("%lld\n", ((s-k*1ll*n)/d)-n);
      else printf("%lld\n", ((k*1ll*n-s)/d)-n);
    }else printf("-1\n");
  }
}