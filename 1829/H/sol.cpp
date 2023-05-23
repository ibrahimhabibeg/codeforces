#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9+7;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for(int i = 0; i<n; i++) scanf("%d", &a[i]);
    vector<vector<int>> dp(n, vector<int>(64));
    for (int i = 0; i < n; i++)
    {
      dp[i][a[i]]++;
      if(i==0) continue;
      for (int j = 0; j < 64; j++){
        dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
        dp[i][a[i]&j] = (dp[i][a[i]&j] + dp[i-1][j])%MOD;
      }
    }
    int res = 0;
    for (int i = 0; i < 64; i++)
      if(__builtin_popcount(i)==k)
        res = (res+dp[n-1][i])%MOD;
    printf("%d\n", res);
  }   
}