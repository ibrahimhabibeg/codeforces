#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll v = a[0], l = 0, r = 0;
    for (int i = 1; i < n; i++){
      if(v>a[i]-r) l+=v-(a[i]-r), v = a[i] - r;
      else r+=a[i]-r-v;
    }
    printf("%lld\n", abs(v)+l+r);
  }   
}