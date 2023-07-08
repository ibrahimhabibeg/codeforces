#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  int dp[k][n+1][k];
  memset(dp, 0, sizeof(dp));
  ll res = 1;
  for (int i = 0; i < n; i++) res = (res*1LL*k)%m;
  for (int s = 0; s < k; s++) dp[s][0][0] = 1;
  for (int s = 0; s < k; s++) for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) for (int x = 0; x < k; x++) if((2*x)%k!=s) 
    dp[s][i+1][(j+x)%k] = (dp[s][i+1][(j+x)%k]+dp[s][i][j])%m;
  for (int s = 0; s < k; s++) res = (res-dp[s][n][s])%m;
  printf("%lld\n", (res+m)%m);
}
