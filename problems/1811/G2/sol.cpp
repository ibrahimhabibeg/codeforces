#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9+7;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d %d", &n, &m);
    int a[n+1]; 
    vector<vector<int>> dp(n, vector<int>(n+1));
    vector<int> ls(n+1), p(n+1), c(n+1);
    for (int j = 1; j <= n; j++) dp[0][j] = 1, scanf("%d", &a[j]);
    for (int i = 1; i <= n; i++) p[i] = ls[a[i]], ls[a[i]] = i;
    for (int i = 1; i < n; i++) for (int j = 1; j <= n; j++) {
      if(i%m==0) dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%MOD;
      else dp[i][j] = (dp[i][p[j]] + dp[i-1][p[j]])%MOD;
    }
    int mxL = 0;
    for (int i = 1; i <= n; i++) if(++c[a[i]]==m){
      mxL++;
      for (int j = 1; j <= n; j++) c[j] = 0;
    }
    int res = 0;
    if(mxL==0) res= 1;
    else for (int i = 1; i <= n; i++) res = (res + dp[m*mxL-1][i])%MOD;
    printf("%d\n", res);
  }   
}