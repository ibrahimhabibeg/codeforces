#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, q, k;
  scanf("%d %d", &n, &q);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a+n);
  for (int i = 0; i < q; i++){
    scanf("%d", &k);
    int mn = a[0] + k;
    ll e = 0;
    for (int i = 0; i < n; i++) mn = min( a[i] + (((n+k)%2==1 && i==n-1)?0:max(0,k-i)) ,mn);
    for (int i = 0; i < n; i++) e+= a[i] + (((n+k)%2==1 && i==n-1)?0:max(0,k-i)) - mn;
    printf("%lld ", mn - ((max(0*1LL, ((k - n + 1)/2)*1LL - e) + n-1) / n));
  }
}