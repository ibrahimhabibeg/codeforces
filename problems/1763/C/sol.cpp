#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll TC, n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    ll a[n], mx = 0;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), mx = max(mx,a[i]);
    if(n==2) printf("%lld\n", max(a[0]+a[1], 2*abs(a[0]-a[1])));
    else if(n==3) printf("%lld\n", max(max(3*a[0], 3*a[2]), max(a[0]+a[1]+a[2],max(3*(a[1]-a[0]), 3*(a[1]-a[2])))));
    else printf("%lld\n", n*mx);
  }   
}