#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n, C, d, h, c, m;
  scanf("%lld%lld", &n, &C);
  vector<ll> p(C+1);
  for (int i = 0; i < n; i++) scanf("%lld%lld%lld", &c, &d, &h), p[c] = max(p[c], h*d);
  for (ll i = 1; i <= C; i++) for (ll t = 2; t*i<=C; t++) p[t*i] = max(p[t*i], p[i]*t);
  for (ll i = 2; i <= C; i++) p[i] = max(p[i], p[i-1]);
  scanf("%lld", &m);
  while(m--){
    scanf("%lld%lld", &h, &d);
    int res = upper_bound(p.begin(), p.end(), h*d) - p.begin();
    if(res>C) printf("-1 ");
    else printf("%d ", res);
  }
}