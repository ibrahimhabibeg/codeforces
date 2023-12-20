#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  ll m;
  cin >> TC;
  while (TC--){
    scanf("%d%lld", &n, &m);
    ll dp[n+1], res=0;
    for (int d = n; d >= 2; d--){
      dp[d] = ((n/d)*1ll*((n/d)-1))/2;
      for (int k = 2; k <= n/d; k++) dp[d] -= dp[k*d];
    }
    for (ll d = n; d >= 2; d--){
      ll t = min(m/(d-1), dp[d]/(d-1));
      m-=(d-1)*t, res+=d*t;
    }
    if(m) printf("-1\n");
    else printf("%lld\n", res);
  }   
}