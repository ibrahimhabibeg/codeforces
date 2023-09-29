#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    pair<int, int> dp[n][2][2];
    for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = make_pair(n+1, n+1);
    if(s[0]=='0') dp[0][0][1] = make_pair(0,1), dp[0][1][1] = make_pair(1,1);
    else dp[0][0][1] = make_pair(1,1), dp[0][1][1] = make_pair(0,1);
    for (int i = 0; i < n-1; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++){
      int c = dp[i][j][k].first, d = dp[i][j][k].second;
      dp[i+1][j][(k+1)%2] = min(dp[i+1][j][(k+1)%2], make_pair(s[i+1]-'0'==j?c:c+1, d));
      if(k==0) dp[i+1][(j+1)%2][1] = min(dp[i+1][(j+1)%2][1], make_pair(s[i+1]-'0'==j?c+1:c, d+1));
    }
    pair<int, int> res = min(dp[n-1][0][0], dp[n-1][1][0]);
    printf("%d %d\n", res.first, res.second);
  }   
}