#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18;

int main(){
  int TC;
  ll pow[5];
  string s;
  pow[0] = 1;
  for (int i = 1; i < 5; i++) pow[i] = 10*pow[i-1];
  cin >> TC;
  while (TC--){
    cin >> s;
    int n = s.length(), a[n+1];
    for (int i = 1; i <= n; i++) a[i] = s[n-i]-'A';
    ll dp[3][n+1][5];
    fill((ll*)dp, (ll*)dp + 3*5*(n+1), -INF);
    dp[0][0][0] = 0;
    for (int j = 0; j<2; j++) for (int i = 0; i<n; i++) for (int k = 0; k<5; k++){
      dp[j][i+1][max(k,a[i+1])] = max(dp[j][i+1][max(k,a[i+1])], dp[j][i][k] + pow[a[i+1]]*(k>a[i+1]?-1:1));
      if(j==0) for (int x = 0; x<5; x++) dp[j+1][i+1][max(k,x)] = max(dp[j+1][i+1][max(k,x)], dp[j][i][k]+pow[x]*(k>x?-1:1));
    }
    ll res = -INF;
    for (int j = 0; j<2; j++) for (int k = 0; k<5; k++) res = max(res, dp[j][n][k]);
    printf("%lld\n", res);
  }   
}