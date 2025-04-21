#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    ll l[n+1], r[n+1], br[n+1];
    int a[n+1], k = 0;
    a[0] = 0, l[0] = 0, r[n] = 0, br[n] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) l[i]=l[i-1] + a[i];
    for (int i = n-1; i >= 0; i--) r[i]=r[i+1] + a[i+1], br[i]=max(br[i+1], r[i]);
    for (int i = 1; i <= n; i++) if(l[i]+br[i]>l[k]+br[k]) k = i;
    printf("%lld\n", l[k]);
  }   
}