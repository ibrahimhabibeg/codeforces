#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF = 1e9;

int main(){
  int TC, n, m, r, a, b, c;
  cin >> TC;
  while (TC--){
    scanf("%d %d %d", &n, &m, &r);
    int dp[n+1][m+1][r+1];
    unordered_map<int, bool> h[n+1], v[m+1];
    for (int s = 0; s <= r; s++) for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j][s] = INF;
    for (int i = 0; i < r; i++){
      scanf("%d %d %d", &a, &b, &c);
      if(b==1) h[c][a] = true;
      else v[c][a] = true;
    }
    dp[0][0][0] = 0;
    for (int s = 0; s <= r; s++) for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++){
      if(s<r&&!h[i][i+j+s+1]&&!v[j][i+j+s+1]) dp[i][j][s+1] = min(dp[i][j][s+1], dp[i][j][s]+1);
      if(i<n&&!h[i+1][i+j+s+1]&&!v[j][i+j+s+1]) dp[i+1][j][s] = min(dp[i+1][j][s], dp[i][j][s]+1);
      if(j<m&&!h[i][i+j+s+1]&&!v[j+1][i+j+s+1]) dp[i][j+1][s] = min(dp[i][j+1][s], dp[i][j][s]+1);
    }
    int res = INF;
    for (int i = 0; i <= r; i++) res = min(res, dp[n][m][i]);
    if(res==INF) printf("-1\n");
    else printf("%d\n", res);
  }   
}