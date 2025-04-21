#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF = 1e9;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n+1];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    a[n] = n+1;
    vector<vector<int>> dp(n+2, vector<int>(n+1, 1));
    for (int i = 1; i < n; i++) dp[0][i] = -INF;
    for (int k = 0; k <= n; k++){
      for (int i = 0; i < n; i++){
        if(a[i]<a[i+1]) dp[k][i+1] = max(dp[k][i+1], 1 + dp[k][i]);
        for (int j = i+2; j <= n; j++) if(a[i]<a[j]) dp[k+1][j] = max(dp[k+1][j], 1 + dp[k][i]);
      }
      if(k>0) printf("%d ", n-dp[k][n]+1);
    }
    printf("\n");
  }   
}