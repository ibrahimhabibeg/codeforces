#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

ll cnt1(ll x){
  ll res = 0;
  while (x) res+=x%2, x/=2;
  return res;
}

int main(){
  int TC, n;
  ll m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%lld", &n, &m);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll res = 1;
    for (int i = 0; i < n-1; i++){
      if(a[i]%a[i+1]!=0 || a[i]<a[i+1]){
        res = 0;
        break;
      }
      ll d = a[i]/a[i+1], mx = m/a[i+1], c = mx;
      vector<ll> primes;
      for (ll p = 2; p*p <= d; p++){
        if(d%p==0) primes.push_back(p);
        while(d%p==0) d/=p;
      }
      if (d>1) primes.push_back(d);
      int x = primes.size();
      for (int y = 1; y < (1<<x); y++){
        ll p = 1;
        for (int z = 0; z < x; z++) if((1<<z)&y) p*=primes[z];
        if(cnt1(y)%2) c-=mx/p;
        else c+=mx/p;
      }
      res = (res*c)%MOD;
    }
    printf("%lld\n", res);
  }   
}