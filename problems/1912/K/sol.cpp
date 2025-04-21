#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 998244353;

int main(){
  int n, a, b;
  scanf("%d", &n);
  ll dp[n][4][4];
  for (int i = 0; i < n; i++) for (int k = 1; k < 4; k++) for (int j = 0; j < 4; j++) dp[i][k][j] = 0;
  for (int i = 0; i < n; i++){
    scanf("%d", &a);
    dp[i][1][a%2]++;
    if(i>0){
      if(a%2==0) dp[i][2][0] = dp[i-1][1][0], dp[i][2][2] = dp[i-1][1][1], dp[i][3][0] = dp[i-1][2][0] + dp[i-1][3][0], dp[i][3][2] = dp[i-1][2][3] + dp[i-1][3][3];
      if(a%2==1) dp[i][2][1] = dp[i-1][1][0], dp[i][2][3] = dp[i-1][1][1], dp[i][3][1] = dp[i-1][2][2] + dp[i-1][3][2], dp[i][3][3] = dp[i-1][2][1] + dp[i-1][3][1];
      for (int k = 1; k < 4; k++) for (int j = 0; j < 4; j++) dp[i][k][j] = (dp[i][k][j] + dp[i-1][k][j])%MOD;
    }
  }
  ll res = 0;
  for (int j = 0; j < 4; j++) res=(res+dp[n-1][3][j])%MOD;
  printf("%lld", res);
}