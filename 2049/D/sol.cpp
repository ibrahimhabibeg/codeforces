#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m;
  ll v;
  scanf("%d%d%lld", &n, &m, &v);
  ll a[n][m], s[n][m];
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%lld", &a[i][j]);
  for (int i = 0; i < n; i++) {
    s[i][0] = a[i][0];
    for (int j = 1; j < m; j++) s[i][j] = s[i][j-1] + a[i][j];
  }
  ll mv[n][m][m];
  for (int i = 0; i < n; i++) for (int L = 1; L <= m; L++) {
    ll mn = 1e13;
    int st;
    for (int j = 0; j < m; j++) {
      int k = (j + L - 1) % m;
      ll diff;
      if(j<=k) diff = s[i][k] - s[i][j] + a[i][j];
      else diff = s[i][m-1] - s[i][j] + a[i][j]  + s[i][k];
      if(diff<mn){
        mn = diff;
        st = j;
      }
    }
    mv[i][st][st+L-1] = mn;
    int j = st - 1;
    if(j<0) j+=m;
    while (j!=st) {
      int k = (j + L - 1) % m;
      ll diff;
      if(j<=k) diff = s[i][k] - s[i][j] + a[i][j];
      else diff = s[i][m-1] - s[i][j] + a[i][j]  + s[i][k];
      mn = min(mn + v, diff);
      mv[i][j][k] = mn;
      j--;
      if(j<0) j+=m;
    }
  }
  ll dp[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(i==0) {
        dp[i][j] = mv[i][0][j];
      } else {
        dp[i][j] = dp[i-1][0] + mv[i][0][j];
        for (int k = 0; k<=j; k++) dp[i][j] = min(dp[i][j], dp[i-1][k] + mv[i][k][j]);
      }
    }
  }
  printf("%lld\n", dp[n-1][m-1]);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}