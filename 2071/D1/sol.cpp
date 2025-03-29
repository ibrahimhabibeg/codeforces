#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int a[N], p[N], n;

int f(ll x){
  if(x<=n) return a[x];
  if(x<=2*n) return p[x/2];
  ll v = x/2;
  return v%2?p[n]:p[n]^f(v);
}

void solve(){
  ll l, r;
  scanf("%lld%lld%lld", &n, &l, &r);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  p[0] = 0;
  for (int i = 1; i <= n; i++) p[i] = p[i-1] ^ a[i];
  if(n%2 == 0) {
    a[n+1] = p[(n+1)/2];
    p[n+1] = p[n] ^ a[n+1];
    n++;
  }
  printf("%d\n", f(r));
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}