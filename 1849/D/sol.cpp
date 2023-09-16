#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  scanf("%d", &n);
  int a[n], dp[n][3][2];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = 1e6;
  dp[0][a[0]][1] = 1;
  for (int i = 0; i < n-1; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 2; k++){
    dp[i+1][a[i+1]][1] = min(dp[i+1][a[i+1]][1], dp[i][j][k]+1);
    if(j>0) dp[i+1][a[i+1]][0] = min(dp[i+1][a[i+1]][0], dp[i][j][k]);
    if(k==1 && a[i+1]>0) dp[i+1][a[i+1]-1][1] = min(dp[i+1][a[i+1]-1][1], dp[i][j][k]);
  }
  int res = 1e6;
  for (int j = 0; j < 3; j++) for (int k = 0; k < 2; k++) res = min(res, dp[n-1][j][k]);
  printf("%d\n", res);
}