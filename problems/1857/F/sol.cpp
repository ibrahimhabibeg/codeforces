#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a, q;
  ll x, y;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    map<ll, ll> c;
    for (int i = 0; i < n; i++) scanf("%d", &a), c[a]++;
    scanf("%d", &q);
    while (q--){
      scanf("%lld%lld", &x, &y);
      if(4*y > x*x) {
        printf("0 ");
        continue;
      }
      ll r = sqrt(x*x-4*y);
      if(r*r!=x*x-4*y || (x+r)%2==1) printf("0 ");
      else if(r==0) printf("%lld ", (c[x/2]*(c[x/2]-1))/2);
      else printf("%lld ", c[(x+r)/2]*c[(x-r)/2]);
    }
    printf("\n");
  }   
}