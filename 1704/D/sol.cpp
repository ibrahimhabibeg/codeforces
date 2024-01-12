#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  ll a;
  while (TC--){
    scanf("%d%d", &n, &m);
    ll mx = 0, mn = 1e18;
    int x = 0;
    for (int i = 1; i <= n; i++){
      ll res = 0;
      for (int j = 1; j <= m; j++)
       scanf("%lld", &a), res+=a*j;
      if(res>mx) mx = res, x = i;
      mn = min(mn, res);
    }
    printf("%d %lld\n", x, mx-mn);
  }   
}