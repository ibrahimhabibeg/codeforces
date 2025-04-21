#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  while(b) {
    ll c = b;
    b = a%b;
    a = c;
  }
  return a;
}

ll diff(ll a, ll b) {
  return b-a+1;
}

pair<ll, ll> maxGcdDiff(ll a, ll b) {
  if(a>b) return make_pair(1, 0);
  ll ra = a, rb = b;
  while(ra<= rb && gcd(ra, rb)!=1) rb--;
  for (ll x = ra+1; x<=b && diff(x,b) > diff(ra, rb); x++){
    for(ll y = b; x<= y && diff(x,y) > diff(ra, rb); y--) {
      if(gcd(x,y)==1) ra = x, rb = y;
    }
  }
  return make_pair(ra, rb);
}

void solve(){
  ll l, r, G;
  scanf("%lld%lld%lld", &l, &r, &G);
  pair<ll, ll> pr = maxGcdDiff((l+G-1)/G, r/G);
  ll x = pr.first*G, y = pr.second*G;
  if(x>y || x<l || x>r || y<l || y>r || gcd(x, y)!=G) printf("-1 -1\n");
  else printf("%lld %lld\n", x, y);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}