#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9+7;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d %d", &n, &m);
    int a[n], dp[n][n];
    for (int j = 0; j < n; j++) dp[0][j] = 1, scanf("%d", &a[j]);
    for (int i = 1; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = 0;
    for (int i = 0; i < n-1; i++) for (int j = 0; j < n; j++) for (int k = j+1; k < n; k++) if((i+1)%m==0 || a[j]==a[k]) 
      dp[i+1][k] = (dp[i+1][k] + dp[i][j])%MOD;
    int i = n - (n%m) - 1, res = 0;
    while (res == 0 && i>=0){
      for (int j = 0; j < n; j++) res = (res + dp[i][j])%MOD;
      i-=m;
    }
    printf("%d\n", max(1,res));
  }   
}