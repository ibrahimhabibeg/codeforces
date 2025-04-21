#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[200005][25][3], UN_REACH = -1e18;

int main(){
  int TC, n, m, x;
  cin >> TC;
  while (TC--){
    scanf("%d %d %d", &n, &m, &x);
    int a[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n+1; i++)  for (int j = 0; j < m+1; j++) for (int k = 0; k < 3; k++) dp[i][j][k] = UN_REACH;
    dp[0][0][0] = 0;
    for (int i = 0; i < n+1; i++) for (int j = 0; j < m+1; j++) for (int k = 0; k < 3; k++){
      if(dp[i][j][k]==UN_REACH) continue;
      for (int j2 = j; j2 <= min(m+1, j+1); j2++) for (int k2 = k; k2 < 3; k2++) 
        dp[i+1][j2][k2] = max(dp[i+1][j2][k2], dp[i][j][k] + (k2==1?a[i+1]+(j2==j?-x:x):0));
    }
    printf("%lld\n", max(dp[n][m][1], dp[n][m][2]));
  }   
}