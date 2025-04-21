#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    char a[n][n+1];
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> rd(2*n-1), ld(2*n+1);
    for (int i = 0; i < n; i++) scanf("%s", &a[i]);
    int res = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
      if(i>0) dp[i][j] = dp[i-1][j] + rd[i+j] + ld[i-j+n-1];
      if((a[i][j]-'0'+dp[i][j])%2==1) res++, dp[i][j]++, rd[i+j]++, ld[i-j+n-1]++;
    } 
    printf("%d\n", res);
  }   
}