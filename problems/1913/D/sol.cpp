#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    ll a[n+1], dp[n+1][2], pdp[n+1], sm = 1;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    stack<int> s;
    s.push(0), s.push(1);
    dp[1][0] = 0, dp[1][1] = 1, pdp[1] = 1, a[0]=-1, dp[0][0] = 0, dp[0][1] = 0, pdp[0] = -1;
    for (int i = 2; i <= n; i++){
      ll d = pdp[s.top()];
      while (a[i]<a[s.top()]){
        sm = (((sm-dp[s.top()][1])%MOD)+MOD)%MOD;
        d = (((d-dp[s.top()][1])%MOD)+MOD)%MOD;
        s.pop();
      }
      d = (((d-pdp[s.top()])%MOD)+MOD)%MOD;
      dp[i][0] = sm;
      dp[i][1] = (dp[i-1][0]+dp[i-1][1]+d)%MOD;
      pdp[i] = (dp[i][1]+pdp[i-1])%MOD;
      s.push(i);
      sm = (sm+dp[i][1])%MOD;
    }
    printf("%lld\n", (dp[n][0]+dp[n][1])%MOD);
  }   
}