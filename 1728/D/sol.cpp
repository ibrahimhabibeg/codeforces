#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main(){
  int TC;
  cin >> TC;
  while (TC--)
  {
    cin >> s;
    int n = s.length(), dp[n][n];
    for (int i = 0; i < n-1; i++){
      if(s[i]==s[i+1]) dp[i][i+1] = 1;
      else dp[i][i+1] = 2;
    }
    for (int L = 4; L <= n; L+=2) for (int i = 0; i+L-1< n; i++){
      int j = i+L-1;
      int ll, lr, rl, rr;
      if(dp[i+2][j]!=1) ll = dp[i+2][j];
      else if(s[i]<s[i+1]) ll = 2;
      else if(s[i]==s[i+1]) ll = 1;
      else ll = 0;

      if(dp[i+1][j-1]!=1) lr = dp[i+1][j-1];
      else if(s[i]<s[j]) lr = 2;
      else if(s[i]==s[j]) lr = 1;
      else lr = 0;

      if(dp[i+1][j-1]!=1) rl = dp[i+1][j-1];
      else if(s[j]<s[i]) rl = 2;
      else if(s[j]==s[i]) rl = 1;
      else rl = 0;

      if(dp[i][j-2]!=1) rr = dp[i][j-2];
      else if(s[j]<s[j-1]) rr = 2;
      else if(s[j]==s[j-1]) rr = 1;
      else rr = 0;

      dp[i][j] = max(min(ll, lr), min(rl,rr));
    }
    if(dp[0][n-1]==2) printf("Alice\n");
    else if(dp[0][n-1]) printf("Draw\n");
    else printf("Bob\n");
  }   
}