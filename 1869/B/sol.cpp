#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, a, b;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d%d%d", &n, &k, &a, &b);
    ll x[n+1], y[n+1];
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &x[i], &y[i]);
    ll mnS = a<=k?0:1e18, mnE = b<=k?0:1e18;
    for (int i = 1; i <= k; i++) mnS = min(mnS, abs(x[a]-x[i]) + abs(y[a]-y[i])), mnE = min(mnE, abs(x[b]-x[i]) + abs(y[b]-y[i]));
    printf("%lld\n", min(mnS+mnE, abs(x[a]-x[b]) + abs(y[a]-y[b])));
  }   
}