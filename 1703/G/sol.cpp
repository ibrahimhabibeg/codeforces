#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    int a[n+1];
    ll r[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    r[0] = r[1] = 0;
    for (int i = 2; i <= n; i++) r[i] = r[i-1] + 1ll*a[i-1];
    for (int i = 0; i <= n; i++) r[i] -= k*1ll*i;
    for (int i = 1; i <= n; i++){
      int j = i;
      while (j>=0 && a[i]) r[j]+=a[i], a[i]/=2, j--;
    }
    ll res = r[0];
    for (int i = 0; i <= n; i++) res = max(res, r[i]);
    printf("%lld\n", res);
  }   
}